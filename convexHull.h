#ifndef _CONVEXHULL_H_
#define _CONVEXHULL_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class convexHull {

private:
    struct Point {
        int x, y;
    };
std::string fileName;
std::vector<Point> points;
public:

    convexHull(std::string fileName); //convexHull constructor
    ~convexHull(); //convexHull deconstructor

    void convertToPoint();

};

#endif
