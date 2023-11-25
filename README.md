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
