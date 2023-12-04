#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <SFML/Graphics.hpp>

class graph {

private:
    std::string filename1;
    std::string filename2;
    std::string filename3;

    int shapeCount;

    std::vector<sf::Vector2f> greenPoints; //Shape 1
    std::vector<sf::Vector2f> bluePoints; //Shape 2
    std::vector<sf::Vector2f> redPoints; //Shape 3

    double minX = MAXFLOAT;
    double minY = MAXFLOAT;
    double maxX = -MAXFLOAT;
    double maxY = -MAXFLOAT;

    sf::ConvexShape greenShape;
    std::vector<sf::CircleShape> greenCircles;

    sf::ConvexShape blueShape;
    std::vector<sf::CircleShape> blueCircles;

    sf::ConvexShape redShape;
    std::vector<sf::CircleShape> redCircles;

    std::vector<sf::Vertex> greenLines;
    std::vector<sf::Vertex> blueLines;
    std::vector<sf::Vertex> redLines;

public:
    graph(std::string filename, int shapeCount);
    graph(std::string filename, std::string filenameBlue, int shapeCount);
    graph(std::string filename, std::string filenameBlue, std::string filenameRed, int shapeCount);

    void sizeWindow();
    void createShapes();
    void setColors();
    void plot();

    ~graph();

};

#endif
