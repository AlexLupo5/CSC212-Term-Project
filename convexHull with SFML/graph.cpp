#include <iostream>
#include "graph.h"
#include "cmath"

sf::RenderWindow graphOutput(sf::VideoMode(800, 600), "Convex Hull Grapher");

std::vector<sf::Vector2f> readFile(std::string filename) { //readFile function which returns an vector of <sf::Vector2f>, instructions based off the SFML library directory
    std::ifstream infile(filename); //Read in the file provied by String filename
    std::vector<sf::Vector2f> points; //Create a vector of <sf::Vector2f>

    std::string line; //Create string line and x for reading through the file
    std::string x;

    while (getline(infile, line)) { //Increments through the file
        std::stringstream strLine(line);

        double tempx = 0; //double tempx and tempy are used to hold the 
        double tempy = 0;
        while (strLine >> x) { //Increments through StrLine
            std::string temp = ""; //Create an empty string to place chars in when reading through each line

            int i = 1; //Index i, skips the "(" and starts at the first number
            while (x[i] != ',') { //Repeats until reacing a ","
                temp += x[i]; //Add each char to temp
                i++;
            }
            tempx = std::stod(temp); //Converts temp to a double and store it in tempx
            i++; //Increment index counter i past the ","
            temp.clear(); //Clear temp for next string

            while (x[i] != ')') { //Repeats until reacing a ")"
                temp += x[i]; //Add each char to temp
                i++;
            }
            tempy = std::stod(temp); //Converts temp to a double and store it in tempy
        }
        points.emplace_back(tempx, tempy); //Add point (tempx and tempy) to points, can be accessed later by points[index].x or points[index].y
    }

    return points; //return the point Vector2f

}

graph::graph(std::string filename1, int shapeCount) { //Graph constructor for passing in one file
    this->filename1 = filename1; //Set filename1 = to the first file passed in
    this->shapeCount = shapeCount; //Set shapeCount equal to the number of shapes being graphed, 1
    greenPoints = readFile(filename1); //Create points from read (filename1)
    sizeWindow(); //Sets size of output window
    createShapes(); //Create shapes based off of shapeCount
    setColors(); //Sets the color of each shape (txt file1 = green)
    plot(); //Plot the one shape

    return;

}

graph::graph(std::string filename1, std::string filename2, int shapeCount) { //Graph constructor for passing in two files
    this->filename1 = filename1; //Set filename1 = to the first file passed in
    this->filename2 = filename2; //Set filename2 = to the second file passed in
    this->shapeCount = shapeCount; //Set shapeCount equal to the number of shapes being graphed, 2
    greenPoints = readFile(filename1); //Create points from read (filename1)
    bluePoints = readFile(filename2); //Create points from read (filename2)
    sizeWindow(); //Sets size of output window
    createShapes(); //Create shapes based off of shapeCount
    setColors(); //Sets the color of each shape (txt file1 = green, txt file2 = blue)
    plot(); //Plot the two shapes

    return;

}

graph::graph(std::string filename1, std::string filename2, std::string filename3, int shapeCount) { //Graph constructor for passing in three files
    this->filename1 = filename1; //Set filename1 = to the first file passed in
    this->filename2 = filename2; //Set filename2 = to the second file passed in
    this->filename3 = filename3; //Set filename3 = to the third file passed in
    this->shapeCount = shapeCount; //Set shapeCount equal to the number of shapes being graphed, 3
    greenPoints = readFile(filename1); //Create points from read (filename1)
    bluePoints = readFile(filename2); //Create points from read (filename2)
    redPoints = readFile(filename3); //Create points from read (filename3)
    sizeWindow(); //Sets size of output window
    createShapes(); //Create shapes based off of shapeCount
    setColors(); //Sets the color of each shape (txt file1 = green, txt file2 = blue, txt file3 = red)
    plot(); //Plot the three shapes

    return;

}

graph::~graph() {

}

void graph::sizeWindow(){ //Set the size of the window function

    if(shapeCount >= 1) { //If shapeCount equals 1 then only need to test the values of file1
        // Calculate the range for all shapes combined
        for (int i = 0; i < greenPoints.size(); i++) {
            sf::Vector2f &point = greenPoints[i];

            if (point.x < minX) { //If point.x < minX, then set minX = point.x, new minimum x value
                minX = point.x;
            }
            if (point.x > maxX) { //If point.x > maxX, then set maxX = point.x, new maximum x value
                maxX = point.x;
            }
            if (point.y < minY) { //If point.y < minY, then set minY = point.y, new minimum y value
                minY = point.y;
            }
            if (point.y > maxY) { //If point.y > maxY, then set maxY = point.y, new maximum y value
                maxY = point.y;
            }

        }
    }

    if(shapeCount >= 2) { //If shapeCount equals 2 then only need to test the values of file1 and file2
        for (int i = 0; i < bluePoints.size(); i++) {
            sf::Vector2f &point = bluePoints[i];

            if (point.x < minX) { //If point.x < minX, then set minX = point.x, new minimum x value
                minX = point.x;
            }
            if (point.x > maxX) { //If point.x > maxX, then set maxX = point.x, new maximum x value
                maxX = point.x;
            }
            if (point.y < minY) { //If point.y < minY, then set minY = point.y, new minimum y value
                minY = point.y;
            }
            if (point.y > maxY) { //If point.y > maxY, then set maxY = point.y, new maximum y value
                maxY = point.y;
            }

        }
    }

    if(shapeCount >= 3) { //If shapeCount equals 3 then test the values of file1, file2, and file3
        for (int i = 0; i < redPoints.size(); i++) {
            sf::Vector2f &point = redPoints[i];

            if (point.x < minX) { //If point.x < minX, then set minX = point.x, new minimum x value
                minX = point.x;
            }
            if (point.x > maxX) { //If point.x > maxX, then set maxX = point.x, new maximum x value
                maxX = point.x;
            }
            if (point.y < minY) { //If point.y < minY, then set minY = point.y, new minimum y value
                minY = point.y;
            }
            if (point.y > maxY) { //If point.y > maxY, then set maxY = point.y, new maximum y value
                maxY = point.y;
            }

        }
    }

    //double rangeX = std::max(abs(minX), abs(maxX));
    //double rangeY = std::max(abs(minY), abs(maxY));

    //graphOutput.setView(sf::View(sf::FloatRect((-2 * rangeX), (-2 * rangeY), (4 * rangeX), (4 * rangeY))));
    sf::View view; //Create view to change the zoom on the graph and center of the graph
    view.setSize(((maxX-minX + (maxX-minX)/10)), -(maxY-minY + (maxY-minY)/10)); //Formula to find the size of the shapes
    view.setCenter((maxX+minX)/2, (maxY+minY)/2); //Formula to get the center of the shape
    graphOutput.setView(view); //Set the graphOutput view equal to view

    return;

}

void graph::createShapes() { //createShapes function

    if(shapeCount >= 1) { //If shapeCount >= 1 then graph the first shape
        greenShape.setPointCount(greenPoints.size());
        for (int i = 0; i < greenPoints.size(); i++) { //Output each point on the graphOutput
            greenShape.setPoint(i, greenPoints[i]);
        }

        /*for (int i = 0; i < greenPoints.size(); i++) {
            sf::Vector2f &point = greenPoints[i];

            sf::CircleShape circle(3);
            circle.setFillColor(sf::Color::Green);
            circle.setPosition(point);
            circle.setOrigin(3, 3);
            greenCircles.push_back(circle);
        }*/
    }

    if(shapeCount >= 2) { //If shapeCount >= 2 then graph the first and second shape
        blueShape.setPointCount(bluePoints.size());
        for (int i = 0; i < bluePoints.size(); i++) { //Output each point on the graphOutput
            blueShape.setPoint(i, bluePoints[i]);
        }

        /*for (int i = 0; i < bluePoints.size(); ++i) {
            sf::Vector2f &point = bluePoints[i];

            sf::CircleShape circle(3);
            circle.setFillColor(sf::Color::Blue);
            circle.setPosition(point);
            circle.setOrigin(3, 3);
            blueCircles.push_back(circle);
        }*/
    }

    if(shapeCount >= 3) { //If shapeCount >= 3 then graph the first, second and third shape
        redShape.setPointCount(redPoints.size());
        for (int i = 0; i < redPoints.size(); ++i) { //Output each point on the graphOutput
            redShape.setPoint(i, redPoints[i]);
        }

        /*for (int i = 0; i < redPoints.size(); ++i) {
            sf::Vector2f &point = redPoints[i];

            sf::CircleShape circle(3);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(point);
            circle.setOrigin(3, 3);
            redCircles.push_back(circle);
        }*/
    }

    return;

}

void graph::setColors() { //setColors function

    greenShape.setFillColor(sf::Color(0, 255, 0, 75)); //Set greenShape plot color to green
    greenShape.setOutlineColor(sf::Color::Green); //Set the outline color of shape 1 to green, can be edited to any color
    greenShape.setOutlineThickness((maxY-minY)/100);

    blueShape.setFillColor(sf::Color(0, 0, 255, 75)); //Set greenShape plot color to blue
    blueShape.setOutlineColor(sf::Color::Blue); //Set the outline color of shape 2 to blue, can be edited to any color
    blueShape.setOutlineThickness((maxY-minY)/100);

    redShape.setFillColor(sf::Color(255, 0, 0, 75)); //Set greenShape plot color to red
    redShape.setOutlineColor(sf::Color::Red); //Set the outline color of shape 3 to red, can be edited to any color
    redShape.setOutlineThickness((maxY-minY)/100);

    return;

}

void graph::plot() { //plot function


    /*sf::Text text;
    text.setString("");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(90, 100);*/


    while (graphOutput.isOpen()) { //While the graphOutput is open, run code below, once graphOutput is graphed, allow to be closed
        sf::Event output;
        while (graphOutput.pollEvent(output)) {
            if (output.type == sf::Event::Closed) {
                graphOutput.close();
            }
        }

        graphOutput.clear((sf::Color::Black)); //Clear the graphout window and can be used to set the color of the graph, might want the graph to be white or black

        //graphOutput.draw(text);

        if(shapeCount >= 1) { //if shapeCount >= 1
            graphOutput.draw(greenShape); //Graph the first shape

            for (int i = 0; i < greenCircles.size(); ++i) {
                //graphOutput.draw(greenCircles[i]);
            }
        }

        if(shapeCount >= 2) { //if shapeCount >= 2
            graphOutput.draw(blueShape); //Graph the second shape

            for (int i = 0; i < blueCircles.size(); ++i) {
                //graphOutput.draw(blueCircles[i]);
            }
        }

        if(shapeCount >= 3) { //if shapeCount >= 3
            graphOutput.draw(redShape); //Graph the third shape

            for (int i = 0; i < redCircles.size(); ++i) {
                //graphOutput.draw(redCircles[i]);
            }
        }
        graphOutput.display(); //Display graphOutput
    }

    return;

}
