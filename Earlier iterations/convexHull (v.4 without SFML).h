#ifndef _CONVEXHULL_H_
#define _CONVEXHULL_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
struct Point {
    int x, y;
};
class convexHull {

private:
    std::string fileName;
    std::vector<Point> pointsTemp;
    std::vector<Point> output;
public:
    convexHull(std::string fileName); //convexHull constructor
    ~convexHull(); //convexHull deconstructor
    static Point temp;

    void convertToPoint();
    void convexHullSolve(Point points[], int n);

    void print();
    void dot();
    void dot2();
    void nonSFMLDot();

    double polarAngle(double x, double y); //Returns the polarAngle of the given (x2- x1,y2- y1) coordinates

    static int orientation(Point p, Point q, Point r);

    Point Top(std::vector<Point> &S);
};

#endif
