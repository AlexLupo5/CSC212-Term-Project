#include "convexHull.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

convexHull::convexHull(std::string fileName) {
    this->fileName = fileName; //Sets fileName to name of file
    convertCoordToXYVect();
    //Reads through the inputFile and puts all x coordinates into
    //xCoordinates vector and all y coordinates in yCoordinates vector

    // // Used for testing // //
    /*for(int i = 0; i < xCoordinates.size(); i++) {
        std::cout << xCoordinates[i] << ", " << yCoordinates[i] << std::endl;
    }*/
    checkForDupl();
sort();
/*for(int i = 0; i < xSorted.size(); i++) {
    std::cout << "(" << xSorted[i] << ", " << ySorted[i] << ")" << std::endl;
}*/
    addToOutput(0); //finds the lowest Y coordinate pair and adds to output
    //curX.push_back(xCoordinates[findLowestYCoordPair()]);
    //curY.push_back(yCoordinates[findLowestYCoordPair()]);
    addToOutput(1); //finds the lowest Y coordinate pair and adds to output
    for(int i = 2; i < xSorted.size(); i++) {

        double area = (xSorted[i-1]-xSorted[i-2])*(ySorted[i]-ySorted[i-2])-(ySorted[i-1]-ySorted[i-2])*(xSorted[i]-xSorted[i-2]);
        if (area < 0) {
            output.pop_back();
            xSorted.erase(xSorted.begin() + i);
            ySorted.erase(ySorted.begin() + i);
            //i--;
        }
        else if (area > 0) {
addToOutput(i);
        }
        else if (area == 0) {
            addToOutput(i);
        }

    }

    /*for(int i = 0; i < xCoordinates.size(); i++) {
        std::cout << "(" << xCoordinates[i] << ", " << yCoordinates[i] << ") = ";
        std::cout << polarAngle(xCoordinates[i] - xCoordinates[findLowestYCoordPair()],yCoordinates[i] - yCoordinates[findLowestYCoordPair()]) << std::endl;
    }*/

//Continue code here

    return;

}

convexHull::~convexHull() {

}

void convexHull::addToOutput(int i) {
    std::string temp = "(" + std::to_string(xSorted[i]) + ", " + std::to_string(ySorted[i]) + ")\n";
    output.push_back(temp);
    //std::cout << "(" + std::to_string(xCoordinates[i]) + ", " + std::to_string(yCoordinates[i]) + ")\n";
    return;
}

void convexHull::checkForDupl() {

    std::vector<int>xTemp;// = xCoordinates;
    std::vector<int>yTemp;// = yCoordinates;

    for(int h = 0; h < xCoordinates.size(); h++) {
        bool dupl = false;
        for (int k = 0; k < xTemp.size(); k++) {
            if ((xCoordinates[h] == xTemp[k]) && (yCoordinates[h] == yTemp[k])) {
                dupl = true;
            }
        }
        if (dupl == false) {
            xTemp.push_back(xCoordinates[h]);
            yTemp.push_back(yCoordinates[h]);
        }
    }
    xCoordinates = xTemp;
    yCoordinates = yTemp;
}

void convexHull::sort() {
    int num = xCoordinates.size();
std::vector<int>xTemp = xCoordinates;
std::vector<int>yTemp = yCoordinates;

    for(int i = 0; i < num; i++) {
        int temp = 0;

        for(int j = 0; j < xTemp.size(); j++) {

            if (polarAngle(xTemp[temp] - xCoordinates[findLowestYCoordPair()],
                           yTemp[temp] - yCoordinates[findLowestYCoordPair()]) >
                polarAngle(xTemp[j] - xCoordinates[findLowestYCoordPair()],
                           yTemp[j] - yCoordinates[findLowestYCoordPair()])) {
                temp = j;
            }

        }

            xSorted.push_back(xTemp[temp]);
            ySorted.push_back(yTemp[temp]);

        std::cout << "(" << xSorted[xSorted.size() - 1] << ", " << ySorted[ySorted.size() - 1] << ") = ";
        std::cout << polarAngle(xSorted[xSorted.size() - 1] - xCoordinates[findLowestYCoordPair()],ySorted[ySorted.size() - 1] - yCoordinates[findLowestYCoordPair()]) << std::endl;

        xTemp.erase(xTemp.begin() + temp);
        yTemp.erase(yTemp.begin() + temp);
    }
//std::cout << std::endl;
/*
        std::cout << "start" << std::endl;
        for(int j = 0; j < xSorted.size(); j++) {
std::cout << "(" << xSorted[j] << ", " << ySorted[j] << ")" << std::endl;
        }
        std::cout << "end" << std::endl;
*/
}

int convexHull::findLowestYCoordPair() {
    int lowestY = 0;

    for (int i = 1; i < yCoordinates.size(); i++) {

        if (yCoordinates[lowestY] > yCoordinates[i]) {
            lowestY = i;
        }

        else if (yCoordinates[lowestY] == yCoordinates[i]) {
            if (xCoordinates[lowestY] > xCoordinates[i]) {
                lowestY = i;
            }
        }
    }

    // // Used for testing // //
    //std::cout << "Lowest Y coordinates is: " << xCoordinates[lowestY] << ", " << yCoordinates[lowestY] << std::endl;
    return lowestY;

}

double convexHull::polarAngle(double x, double y) { //Returns the polarAngle of the given (x,y) coordinates
    //return atanf(y/x) * 180/3.14159265359;
    return std::atan2(y, x) * (180.0 / M_PI);
};

void convexHull::printOutput() {
    for(int i = 0; i < output.size(); i++) {
        std::cout << output[i];
    }
    return;
}

void convexHull::convertCoordToXYVect() {
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

void convexHull::Visualize(){
    std::ofstream dotfile(fileName + ".dot");
    if (dotfile.is_open()){
        dotfile << "graph convexHull";
        dotfile << "{\n";
        for(int i = 0; i < output.size(); i++) {
            dotfile << output[i] << ";\n";
        }
        dotfile << "}\n";
        dotfile.close();
    }
}
