#include <iostream>
#include <fstream>
#include <vector>
#include "Project.h"

int main(int argc, char* argv[]) {
    //Get points from the file
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cout << "Could not open file";
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

    //Stores points in .cpp file
    Convex Hull(pointsvect);

    //Do the Convex Hull
    Hull.computeConvex();

    //Close the file
    inputFile.close();

    //Get Convex Hull
    std::vector<Point> hull = Hull.getConvex();

    return 0;
}
