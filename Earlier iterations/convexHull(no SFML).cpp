#include <iostream>
#include "convexHull.h"
#include <cmath>

const int PI = 3.14159265359;

convexHull::convexHull(std::string inputFileName) {
    this->inputFileName = inputFileName;  ///Creation of file name
    parsePoints();

    Point inputPoints[pointsVector.size()];

    for (int i = 0; i < pointsVector.size(); i++) {
        inputPoints[i].x = pointsVector[i].x;    ///storing respective x and y points in vector
        inputPoints[i].y = pointsVector[i].y;
    }

    solveConvexHull(inputPoints, pointsVector.size());  
}

convexHull::~convexHull() {}

void convexHull::solveConvexHull(Point inputPoints[], int size) {
    int lowestY = inputPoints[0].y;                            ///Find the lowest y point to be the initial point to establish convex hull
    int lowestIndex = 0;

    for (int i = 0; i < size; i++) {
        int y = inputPoints[i].y;

        if ((y < lowestY) || ((lowestY == y) && (inputPoints[i].x < inputPoints[lowestIndex].x))) {
            lowestY = inputPoints[i].y;                /// If lowest y value is matched, find lowest x and that will be starting point
            lowestIndex = i;
        }
    }

    Point tempPoint = inputPoints[0];        ///swap pivot point w/ first point in array
    inputPoints[0] = inputPoints[lowestIndex];
    inputPoints[lowestIndex] = tempPoint;

    pivotPoint = inputPoints[0];

    std::vector<Point> sortedPoints;
    for (int i = 1; i < pointsVector.size(); i++) {  ///set pivot point for future reference
        sortedPoints.push_back(inputPoints[i]);
    }

    int num = sortedPoints.size();

    for (int i = 1; i <= num; i++) {
        int ang = 0;

        for (int j = 0; j < sortedPoints.size(); j++) {
            if (calculatePolarAngle(sortedPoints[ang].x - inputPoints[0].x,
                                     sortedPoints[ang].y - inputPoints[0].y) ==
                calculatePolarAngle(sortedPoints[j].x - inputPoints[0].x,
                                     sortedPoints[j].y - inputPoints[0].y)) {
                ///If the angles are equal farthest distance is chosen
                if ((calculateDistance(sortedPoints[ang], inputPoints[0])) >
                    (calculateDistance(sortedPoints[j], inputPoints[0]))) {
                    ang = j;
                }
            } else {
              ///Choose smaller angle as point
                if (calculatePolarAngle(sortedPoints[ang].x - inputPoints[0].x,
                                         sortedPoints[ang].y - inputPoints[0].y) >
                    calculatePolarAngle(sortedPoints[j].x - inputPoints[0].x,
                                         sortedPoints[j].y - inputPoints[0].y)) {
                    ang = j;
                }
            }
        }
        inputPoints[i] = sortedPoints[ang];
        sortedPoints.erase(sortedPoints.begin() + ang);
    }

    int index = 1;
    for (int i = 1; i < size; i++) {
        while ((i < size - 1) && (calculateOrientation(pivotPoint, inputPoints[i], inputPoints[i + 1]) == 0)) {
            i++;
        }
        inputPoints[index] = inputPoints[i];
        index = index + 1;
    }

    if (index < 3) {        ///If index contains less than 3 points, return as convex cannot be formed
        return;
    }

    for (int i = 0; i < 3; i++) {
        convexHullPoints.push_back(inputPoints[i]);      ///Push points into vec
    }

    for (int i = 3; i < index; i++) {
        while (convexHullPoints.size() > 1 &&
               calculateOrientation(topPoint(convexHullPoints), convexHullPoints[convexHullPoints.size() - 1],
                                    inputPoints[i]) != 2) {
            convexHullPoints.pop_back();
        }
        convexHullPoints.push_back(inputPoints[i]);
    }
}

Point convexHull::pivotPoint = Point();

Point convexHull::topPoint(std::vector<Point> &pointsVector) {
    Point point = pointsVector[pointsVector.size() - 1];
    pointsVector.pop_back();
    Point answer = pointsVector[pointsVector.size() - 1];
    pointsVector.push_back(point);
    return answer;
}

double convexHull::calculatePolarAngle(double x, double y) {
    return std::atan2(y, x) * (180.0 / PI);
}

int convexHull::calculateOrientation(Point point1, Point point2, Point point3) {
    int orientation = (point2.y - point1.y) * (point3.x - point2.x) -
                      (point2.x - point1.x) * (point3.y - point2.y);

    if (orientation >= 0) {
        if (orientation > 0) {    ///Clockwise case
            return 1;
        } else {      ///Colinear case
            return 0;
        }
    } else {      ///Counterclockwise case
        return 2;
    }
}

void convexHull::parsePoints() {
    std::ifstream inputFile(inputFileName);
    std::string line;
    int x, y;

    while (getline(inputFile, line)) {
        std::stringstream strLine(line);
        strLine >> x;
        strLine.ignore(); 
