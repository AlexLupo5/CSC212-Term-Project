#include "convexHull.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

convexHull::convexHull(std::string fileName) {
    this->fileName = fileName;
    convertCoordToXYVect();
    checkForDupl();
    sort();
    addToOutput(0);
    addToOutput(1);

    for (int i = 2; i < xSorted.size(); i++) {
        double area = (xSorted[i - 1] - xSorted[i - 2]) * (ySorted[i] - ySorted[i - 2]) - 
                      (ySorted[i - 1] - ySorted[i - 2]) * (xSorted[i] - xSorted[i - 2]);

        if (area < 0) {
            output.pop_back();
            xSorted.erase(xSorted.begin() + i);
            ySorted.erase(ySorted.begin() + i);
        } else if (area > 0) {
            addToOutput(i);
        } else if (area == 0) {
            addToOutput(i);
        }
    }

    return;
}

void convexHull::addToOutput(int i) {
    std::string temp = "(" + std::to_string(xSorted[i]) + ", " + std::to_string(ySorted[i]) + ")\n";
    output.push_back(temp);
    return;
}

void convexHull::checkForDupl() {
    std::vector<int> xTemp;
    std::vector<int> yTemp;

    for (int h = 0; h < xCoordinates.size(); h++) {
        bool dupl = false;
        for (int k = 0; k < xTemp.size(); k++) {
            if ((xCoordinates[h] == xTemp[k]) && (yCoordinates[h] == yTemp[k])) {
                dupl = true;
            }
        }
        if (!dupl) {
            xTemp.push_back(xCoordinates[h]);
            yTemp.push_back(yCoordinates[h]);
        }
    }
    xCoordinates = xTemp;
    yCoordinates = yTemp;
}


void convexHull::visualize() {
    std::ofstream dotfile(fileName + ".dot");
    if (dotfile.is_open()) {
        dotfile << "graph convexHull";
        dotfile << "{\n";
        for (int i = 0; i < output.size(); i++) {
            dotfile << output[i] << ";\n";
        }
        dotfile << "}\n";
        dotfile.close();
    }
}
