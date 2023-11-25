# CSC212-Term-Project
**Project:
Convex Hull

Problem/Solution:


**Requirements:
**Convex Hull to**
^^^

**_Implement Graham’s Scan algorithm_**
- find a way to save a visualization
  - can generate a DOT file

**_Read a set of points from a file_**

**Status Update to**
convexHull.cpp
  * Added convexHull(), ~convexHull(), convertCordToVect(), findLowestY(), polarAngle(int x, int y), addToOutput(int i), printOutput()
    * convertCoordToXYVect() - can read through a file and sort the x and y coordinates into an x int vector and a y int vector
    * findLowestY() - finds the lowest Y coordinate in the Y vector, is used in Graham's Scan algorithm
    * polarAngle(int x, int y) - finds the polar angle of the (x2-x1,y2-y1) coordinates
    * addToOutput(int i) - adds the x and y coordinates at location i to output
    * printOutput() - prints the output vector
  
**Status Update to**
convexHull.h
  * Added to private: std::string fileName, std::vector <int> xCoordinates, std::vector <int> yCoordinates, std::vector <std::string> output, std::vector <int> curX, std::vector <int> curY
  * Added to public: convexHull(), ~convexHull(), convertCoordToXYVect(), findLowestY(), polarAngle(int x, int y), addToOutput(int i), printOutput()

**Status Update to**
Project.cpp
  * Added Convex(std::vector<Point> pointsvect), ~Convex(), computeConvex(), orienation(Point a, Point b, Point c), getConvex(), and compare(Point a, Point b)
    * Convex(std::vector<Point> pointsvect) - Convex Hull constructor
    * ~Convex() = Convex Hull destructor
    * computeConvex() - The main function that computes the Convex hull with the given points and uses Graham's Scan algorithm
    * orientation(Point a, Point b, Point c) - Tells you wheater the Point is Collinear, Clockwise, or Counterclockwise
    * getConvex() - Returns the Convex Hull points
    * compare(Point a, Point b) - Compares two points based on there orientation

**Status Update to**
Project.h
  * Added to private: Point temp, std::vector<Point> Point, std::vector<Point> ConHull
  * Added to public: Convex(std::vector<Point> pointsvect), ~Convex(), int orientation(Point a, Point b, Point c), void computeConvex(), std::vector<Point> getConvex(), bool compare(Point a, Point b)
