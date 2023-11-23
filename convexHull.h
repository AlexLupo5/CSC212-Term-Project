#ifndef _CONVEXHULL_H_
#define _CONVEXHULL_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class convexHull {

private:
    std::string fileName;
std::vector <int> xCordinates;
std::vector <int> yCordinates;

public:

    convexHull(std::string fileName); //convexHull constructor

    ~convexHull(); //convexHull deconstructor

    void convertCordToVect();

};

#endif
