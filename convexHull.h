#ifndef _CONVEXHULL_H_
#define _CONVEXHULL_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class convexHull {

private:
    std::string fileName;
    std::vector <int> xCoordinates;
    std::vector <int> yCoordinates;
    int lowX = 0;
    int lowY = 0;
    std::vector <std::string> output;

public:

    convexHull(std::string fileName); //convexHull constructor
    ~convexHull(); //convexHull deconstructor

    void convertCordToVect();
    int findLowestYCoordPair();

    void addToOutput(int i);
    void printOutput();

    double polarAngle(int x, int y); //Returns the polarAngle of the given (x2- x1,y2- y1) coordinates

};

#endif
