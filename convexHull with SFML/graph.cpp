#include <iostream>
#include "graph.h"
#include "cmath"

sf::RenderWindow graphOutput(sf::VideoMode(800, 600), "Convex Hull Grapher");

std::vector<sf::Vector2f> readFile(std::string filename) {
    std::ifstream infile(filename);
    std::vector<sf::Vector2f> points;

    std::string line;
    std::string x;

    while (getline(infile, line)) {
        std::stringstream strLine(line);

        double tempx = 0;
        double tempy = 0;
        while (strLine >> x) {
            std::string temp = "";

            int i = 1;
            while (x[i] != ',') {
                temp += x[i];
                i++;
            }
            tempx = std::stod(temp);
            i++;
            temp.clear();

            while (x[i] != ')') {
                temp += x[i];
                i++;
            }
            tempy = std::stod(temp);
        }
        points.emplace_back(tempx, tempy);
    }

    return points;

}

graph::graph(std::string filename1, int shapeCount) {
    this->filename1 = filename1;
    this->shapeCount = shapeCount;
    greenPoints = readFile(filename1);
    sizeWindow();
    createShapes();
    setColors();
    plot();

    return;

}

graph::graph(std::string filename1, std::string filename2, int shapeCount) {
    this->filename1 = filename1;
    this->filename2 = filename2;
    this->shapeCount = shapeCount;
    greenPoints = readFile(filename1);
    bluePoints = readFile(filename2);
    sizeWindow();
    createShapes();
    setColors();
    plot();

    return;

}

graph::graph(std::string filename1, std::string filename2, std::string filename3, int shapeCount) {
    this->filename1 = filename1;
    this->filename2 = filename2;
    this->filename3 = filename3;
    this->shapeCount = shapeCount;
    greenPoints = readFile(filename1);
    bluePoints = readFile(filename2);
    redPoints = readFile(filename3);
    sizeWindow();
    createShapes();
    setColors();
    plot();

    return;

}

graph::~graph() {

}

void graph::sizeWindow(){

    if(shapeCount >= 1) {
        // Calculate the range for all shapes combined
        for (int i = 0; i < greenPoints.size(); i++) {
            sf::Vector2f &point = greenPoints[i];

            if (point.x < minX) {
                minX = point.x;
            }
            if (point.x > maxX) {
                maxX = point.x;
            }
            if (point.y < minY) {
                minY = point.y;
            }
            if (point.y > maxY) {
                maxY = point.y;
            }

        }
    }

    if(shapeCount >= 2) {
        for (int i = 0; i < bluePoints.size(); i++) {
            sf::Vector2f &point = bluePoints[i];

            if (point.x < minX) {
                minX = point.x;
            }
            if (point.x > maxX) {
                maxX = point.x;
            }
            if (point.y < minY) {
                minY = point.y;
            }
            if (point.y > maxY) {
                maxY = point.y;
            }

        }
    }

    if(shapeCount >= 3) {
        for (int i = 0; i < redPoints.size(); i++) {
            sf::Vector2f &point = redPoints[i];

            if (point.x < minX) {
                minX = point.x;
            }
            if (point.x > maxX) {
                maxX = point.x;
            }
            if (point.y < minY) {
                minY = point.y;
            }
            if (point.y > maxY) {
                maxY = point.y;
            }

        }
    }

    double rangeX = std::max(abs(minX), abs(maxX));
    double rangeY = std::max(abs(minY), abs(maxY));

    //graphOutput.setView(sf::View(sf::FloatRect((-2 * rangeX), (-2 * rangeY), (4 * rangeX), (4 * rangeY))));
    sf::View view;
    view.setSize(((maxX-minX + (maxX-minX)/10)), -(maxY-minY + (maxY-minY)/10));
    view.setCenter((maxX+minX)/2, (maxY+minY)/2);
    graphOutput.setView(view);

    return;

}

void graph::createShapes() {

    if(shapeCount >= 1) {
        greenShape.setPointCount(greenPoints.size());
        for (int i = 0; i < greenPoints.size(); i++) {
            greenShape.setPoint(i, greenPoints[i]);
        }

        for (int i = 0; i < greenPoints.size(); i++) {
            sf::Vector2f &point = greenPoints[i];

            sf::CircleShape circle(3);
            circle.setFillColor(sf::Color::Green);
            circle.setPosition(point);
            circle.setOrigin(3, 3);
            greenCircles.push_back(circle);
        }
    }

    if(shapeCount >= 2) {
        blueShape.setPointCount(bluePoints.size());
        for (int i = 0; i < bluePoints.size(); i++) {
            blueShape.setPoint(i, bluePoints[i]);
        }

        for (int i = 0; i < bluePoints.size(); ++i) {
            sf::Vector2f &point = bluePoints[i];

            sf::CircleShape circle(3);
            circle.setFillColor(sf::Color::Blue);
            circle.setPosition(point);
            circle.setOrigin(3, 3);
            blueCircles.push_back(circle);
        }
    }

    if(shapeCount >= 3) {
        redShape.setPointCount(redPoints.size());
        for (int i = 0; i < redPoints.size(); ++i) {
            redShape.setPoint(i, redPoints[i]);
        }

        for (int i = 0; i < redPoints.size(); ++i) {
            sf::Vector2f &point = redPoints[i];

            sf::CircleShape circle(3);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(point);
            circle.setOrigin(3, 3);
            redCircles.push_back(circle);
        }
    }

    return;

}

void graph::setColors() {

    greenShape.setFillColor(sf::Color(0, 255, 0, 75)); //Set greenShape plot color to green
    greenShape.setOutlineColor(sf::Color::Green);
    greenShape.setOutlineThickness((maxY-minY)/100);

    blueShape.setFillColor(sf::Color(0, 0, 255, 75)); //Set greenShape plot color to blue
    blueShape.setOutlineColor(sf::Color::Blue);
    blueShape.setOutlineThickness((maxY-minY)/100);

    redShape.setFillColor(sf::Color(255, 0, 0, 75)); //Set greenShape plot color to red
    redShape.setOutlineColor(sf::Color::Red);
    redShape.setOutlineThickness((maxY-minY)/100);

    return;

}

void graph::plot() {


    /*sf::Text text;
    text.setString("");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(90, 100);*/


    while (graphOutput.isOpen()) {
        sf::Event output;
        while (graphOutput.pollEvent(output)) {
            if (output.type == sf::Event::Closed) {
                graphOutput.close();
            }
        }

        graphOutput.clear((sf::Color::Black));

        //graphOutput.draw(text);

        if(shapeCount >= 1) {
            graphOutput.draw(greenShape);

            for (int i = 0; i < greenCircles.size(); ++i) {
                //graphOutput.draw(greenCircles[i]);
            }
        }

        if(shapeCount >= 2) {
            graphOutput.draw(blueShape);

            for (int i = 0; i < blueCircles.size(); ++i) {
                //graphOutput.draw(blueCircles[i]);
            }
        }

        if(shapeCount >= 3) {
            graphOutput.draw(redShape);

            for (int i = 0; i < redCircles.size(); ++i) {
                //graphOutput.draw(redCircles[i]);
            }
        }
        graphOutput.display();
    }

    return;

}
