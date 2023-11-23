# CSC212-Term-Project
**Project:
Convex Hull

Problem/Solution:


**Requirements:
**Convex Hull**
^^^

**_Implement Graham’s Scan algorithm_**
- find a way to save a visualization
  - can generate a DOT file

**_Read a set of points from a file_**

**Status Update**
convexHull.cpp
  * Added convexHull(), ~convexHull(), convertCordToVect(), findLowestY(), polarAngle(int x, int y)
    * convertCordToVect() - can read through a file and sort the x and y coordinates into an x int vector and a y int vector
    * findLowestY() - finds the lowest Y coordinate in the Y vector, is used in Graham's Scan algorithm
    * polarAngle(int x, int y) - finds the polar angle of the (x,y) coordinates
**Status Update**
convexHull.h
  * Added to private: std::string fileName, std::vector <int> xCoordinates, std::vector <int> yCoordinates
  * Added to public: convexHull(), ~convexHull(), convertCordToVect(), findLowestY(), polarAngle(int x, int y)
