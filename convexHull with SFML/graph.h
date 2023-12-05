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
    std::string filename1; //Create three strings that hold the names of three filenames
    std::string filename2;
    std::string filename3;

    int shapeCount; //Int that holds the amount of shapes being graphed

    std::vector<sf::Vector2f> greenPoints; //Shape 1
    std::vector<sf::Vector2f> bluePoints; //Shape 2
    std::vector<sf::Vector2f> redPoints; //Shape 3

    double minX = MAXFLOAT; //Holds the max float value for a more accurate comparison between minX points
    double minY = MAXFLOAT; //Holds the max float value for a more accurate comparison between minY points
    double maxX = -MAXFLOAT; //Holds the negative max float value for a more accurate comparison between maxX points
    double maxY = -MAXFLOAT; //Holds the negative max float value for a more accurate comparison between maxY points

    sf::ConvexShape greenShape; //Create the first shape named greenShape

    sf::ConvexShape blueShape; //Create the second shape named blueShape

    sf::ConvexShape redShape; //Create the third shape named redShape

public:
    graph(std::string filename, int shapeCount); //Constructor for one shape
    graph(std::string filename, std::string filenameBlue, int shapeCount); //Constructor for second shape
    graph(std::string filename, std::string filenameBlue, std::string filenameRed, int shapeCount); //Constructor for third shape

    ~graph(); //graph deconstructor

    void sizeWindow(); //sizeWindow function
    void createShapes(); //createShapes function
    void setColors(); //setColors function
    void plot(); //plot function

};

#endif
