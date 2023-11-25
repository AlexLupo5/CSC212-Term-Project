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
    std::vector <int> curX;
    std::vector <int> curY;
    std::vector <std::string> output;

public:

    convexHull(std::string fileName); //convexHull constructor
    ~convexHull(); //convexHull deconstructor

    void convertCoordToXYVect();
    int findLowestYCoordPair();

    void addToOutput(int i);
    void printOutput();

    double polarAngle(double x, double y); //Returns the polarAngle of the given (x2- x1,y2- y1) coordinates

};

#endif
