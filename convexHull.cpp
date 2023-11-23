#include "convexHull.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

convexHull::convexHull(std::string fileName) {
    this->fileName = fileName; //Sets fileName to name of file
    convertCordToVect();
    //Reads through the inputFile and puts all x coordinates into
    //xCoordinates vector and all y coordinates in yCoordinates vector

    // // Used for testing // //
    /*for(int i = 0; i < xCoordinates.size(); i++) {
        std::cout << xCoordinates[i] << ", " << yCoordinates[i] << std::endl;
    }*/

    findLowestY();

}

convexHull::~convexHull() {

}

void convexHull::findLowestY() {
    int lowestY = 0;

    for (int i = 1; i < yCoordinates.size(); i++) {

        if (yCoordinates[lowestY] > yCoordinates[i]) {
            lowestY = i;
        }

        else if (yCoordinates[lowestY] == yCoordinates[i]) {
            if (xCoordinates[lowestY] > xCoordinates[i]) {
                lowestY = yCoordinates[i];
            }
        }

    }

    // // Used for testing // //
    //std::cout << "Lowest Y coordinates is: " << xCoordinates[lowestY] << ", " << yCoordinates[lowestY] << std::endl;

}

double convexHull::polarAngle(int x, int y) { //Returns the polarAngle of the given (x,y) coordinates
    return atan(y/x);
};

void convexHull::convertCordToVect() {
    //Reads through the inputFile and puts all x coordinates into
    //xCoordinates vector and all y coordinates in yCoordinates vector
    std::ifstream infile(fileName);
    std::string line;
    int num = 0;
    std::string x;

    while (getline(infile, line)) {
        std::stringstream strLine(line);

        while (strLine >> x) {
            //std::cout << x << " ";
            std::string temp = "";

            int i = 1;
            while (x[i] != ',') {
                temp += x[i];
                i++;
            }
            xCoordinates.push_back(std::stoi(temp));
            i++;
            temp.clear();
            while (x[i] != ')') {
                temp += x[i];
                i++;
            }
            yCoordinates.push_back(std::stoi(temp));
        }
    }
    return;

}
