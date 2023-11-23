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

public:

    convexHull(std::string fileName); //convexHull constructor

    ~convexHull(); //convexHull deconstructor

    void convertCordToVect();

    void findLowestY();

    double polarAngle(int x, int y); //Returns the polarAngle of the given (x,y) coordinates

};

#endif
