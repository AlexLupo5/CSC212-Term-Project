#include "convexHull.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

convexHull::convexHull(std::string fileName) {
    this->fileName = fileName; //Sets fileName to name of file
    convertCordToVect();
    //Reads throught the inputFile and puts all x cordinates into
    //xCordinates vector and all y cordinates in yCordinates vector

    // // Used for testing // //
    /*for(int i = 0; i < xCordinates.size(); i++) {
        std::cout << xCordinates[i] << ", " << yCordinates[i] << std::endl;
    }*/

}

convexHull::~convexHull() {

}

void convexHull::convertCordToVect() {
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
            xCordinates.push_back(std::stoi(temp));
            i++;
            temp.clear();
            while (x[i] != ')') {
                temp += x[i];
                i++;
            }
            yCordinates.push_back(std::stoi(temp));
        }
    }
    return;

}
