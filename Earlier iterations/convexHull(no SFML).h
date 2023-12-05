#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

struct Point {
    int x;
    int y;
};

class ConvexHull {
private:
    std::string inputFileName;
    std::vector<Point> pointsVector;
    std::vector<Point> convexHullPoints;
    static Point pivotPoint;

public:
    ConvexHull(std::string inputFileName);
    ~ConvexHull();

    void solveConvexHull(Point inputPoints[], int size);
    Point topPoint(std::vector<Point> &pointsVector);
    double calculatePolarAngle(double x, double y);
    int calculateOrientation(Point point1, Point point2, Point point3);
    void parsePoints();

    // Add any other necessary functions for your implementation

    // Getters
    const std::vector<Point>& getConvexHullPoints() const { return convexHullPoints; }
};

#endif // CONVEXHULL_H
