#include <iostream>
#include <fstream>
#include <vector>
#include "Project.h"

int main(int argc, char* argv[]) {
    //Get points from the file
    std::ifstream inputFile(argv[1]);
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

    //Close the file
    inputFile.close();

    //Do the Convex hull
    std::vector<Point> hull = convexHull(points);
    
    return 0;
}
