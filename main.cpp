#include <iostream>
#include <fstream>
#include <vector>
#include "Project.h"

int main() {
    //Get points from the file
    std::ifstream inputFile("points.txt");
    if (!inputFile.is_open()) {
        std::cout << "Error opening file";
        std::cout << "\n";
        return 1;
    }

    //Insert the number of points
    int Points;
    inputFile >> Points;

    //Save the points in the vector
    std::vector<Point> pointsvect(Points);
    for (int i = 0; i < Points; i++) {
        inputFile >> pointsvect[i].x >> pointsvect[i].y;
    }

    inputFile.close();

    //Do the Convex hull
    std::vector<Point> hull = convexHull(points);
    return 0;
}
