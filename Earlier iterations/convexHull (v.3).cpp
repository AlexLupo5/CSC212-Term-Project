#include <iostream>
#include <cmath>
#include "convexHull.h"

const int PI = 3.14159265359;

convexHull::convexHull(std::string fileName) {
    this->fileName = fileName;

    convertToPoint();

    if(pointsTemp.size() < 3) {
        std::cout << "Convex Hull is not possible" << std::endl;
    }

    Point points[pointsTemp.size()];

    for(int i = 0; i < pointsTemp.size(); i++) {
        points[i].x = pointsTemp[i].x;
        points[i].y = pointsTemp[i].y;
    }

    convexHullSolve(points, pointsTemp.size());
}

void convexHull::convexHullSolve(Point points[], int size){

    int lowesty = points[0].y;
    int lowestval = 0;
    for (int i = 0; i < size; i++){
        int y = points[i].y;

        if ((y < lowesty) || ((lowesty == y && points[i].x < points[lowestval].x))){
            lowesty = points[i].y;
            lowestval = i;
        }
    }

    Point ptemp = points[0];
    points[0] = points[lowestval];
    points[lowestval] = ptemp;

    temp = points[0];
    //std::cout << "lowest y = " << points[0].x << "," << points[0].y << std::endl;
    //qsort(&points[1], size - 1, sizeof(Point), compare);

    // //Sort Added// //

std::vector <Point> pointSort;
    for(int i = 1; i < pointsTemp.size(); i++) {
        pointSort.push_back(points[i]);
    }
    //for(int i = 0; i < pointsTemp.size(); i++) {
//std::cout << pointSort[i].x << ", " << pointSort[i].y << std::endl;
    //}
    //std::cout << std::endl;

    int num = pointSort.size();

    for(int i = 1; i <= num; i++) {
        int ang = 0;

        for(int j = 0; j < pointSort.size(); j++) {

            if (polarAngle(pointSort[ang].x - points[0].x,
                           pointSort[ang].y - points[0].y) ==
                polarAngle(pointSort[j].x - points[0].x,
                           pointSort[j].y - points[0].y)) {

                if((sqrt(pow(pointSort[ang].x,2) + pow(pointSort[ang].y, 2))) >
                   (sqrt(pow(pointSort[j].x,2) + pow(pointSort[j].x, 2)))) {
                    ang = j;
                }
            } else {

            if (polarAngle(pointSort[ang].x - points[0].x,
                           pointSort[ang].y - points[0].y) >
                polarAngle(pointSort[j].x - points[0].x,
                           pointSort[j].y - points[0].y)) {


                    ang = j;
                }
            }

        }

        points[i] = (pointSort[ang]);

        //std::cout << i << " = (" << points[i].x << ", " << points[i].y << ") = ";
        //std::cout << polarAngle(points[i].x - points[0].x,points[i].y - points[0].y) << std::endl;

        pointSort.erase(pointSort.begin() + ang);

    }

    // //Sort End// //

    int index = 1;
    for (int i = 1; i < size; i++){
        while (i < size - 1 && orientation(temp, points[i],points[i + 1]) == 0){
            i++;
        }
        points[index] = points[i];
        index++;
    }

    if (index < 3){
        return;
    }

    for(int i = 0; i < 3; i++) {
        output.push_back(points[i]);
    }

    for (int i = 3; i < index; i++){
        while (output.size() > 1 && orientation(Top(output), output[output.size() - 1], points[i]) != 2){
            output.pop_back();
        }
        output.push_back(points[i]);
    }
}

convexHull::~convexHull(){

}

Point convexHull::temp = Point();

Point convexHull::Top(std::vector<Point> &vect){
    Point point = vect[vect.size()-1];
    vect.pop_back();
    Point answer = vect[vect.size()-1];
    vect.push_back(point);
    return answer;
}

int convexHull::distance(Point point1, Point point2){
    return (point1.x - point2.x)*(point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y);
}

double convexHull::polarAngle(double x, double y) { //Returns the polarAngle of the given (x,y) coordinates
    return std::atan2(y, x) * (180.0 / PI);
}

int convexHull::orientation(Point point1, Point point2, Point point3){
    int orient = (point2.y - point1.y) * (point3.x - point2.x) - (point2.x - point1.x) * (point3.y - point2.y);

    //Colinear
    if (orient >= 0) {
        //Clockwise
        if (orient > 0){
            return 1;
        }
        else {
            return 0;
        }
    }
        //Counterclockwise
    else{
        return 2;
    }
}

/*int convexHull::compare(const void *point1, const void *point2){
    Point *tpoint1 = (Point *)point1;
    Point *tpoint2 = (Point *)point2;

    if (orientation(temp, *tpoint1, *tpoint2) == 0){
        if (distance(temp, *tpoint2) >= distance(temp, *tpoint1)){
            return -1;
        }
        else{
            return 1;
        }
    }

    if (orientation(temp, *tpoint1, *tpoint2) == 2){
        return -1;
    }
    else{
        return 1;
    }
}*/

void convexHull::convertToPoint() {
    //Reads through the inputFile and puts all x coordinates into
    //points.x vector and all y coordinates in points.y vector
    std::ifstream infile(fileName);
    std::string line;
    int num = 0;
    std::string x;

    while (getline(infile, line)) {
        std::stringstream strLine(line);
        int tempx = 0;
        int tempy = 0;
        while (strLine >> x) {
            //std::cout << x << " ";
            std::string temp = "";

            int i = 1;
            while (x[i] != ',') {
                temp += x[i];
                i++;
            }
            tempx = std::stoi(temp);
            i++;
            temp.clear();
            while (x[i] != ')') {
                temp += x[i];
                i++;
            }
            tempy = std::stoi(temp);
        }

        bool duplCheck = false;
        for(int j = 0; j < pointsTemp.size(); j++) {
            if((pointsTemp[j].x == tempx) && (pointsTemp[j].y == tempy)) {
                duplCheck = true;
            }
        }
        if(duplCheck == false) {
            pointsTemp.push_back({tempx, tempy});
        }
    }
}

void convexHull::print() {
std::vector<Point> out = output;
    while (out.size() > 0){
        Point point = out[out.size()-1];
        std::cout << "(" << point.x << ", " << point.y <<")\n";
        out.pop_back();
    }
}

void convexHull::dot() {
    //Creating a dot file
    std::ofstream File("convexHull.dot");

    //Initializing vector of points for points that aren't edge vertices
    std::vector<Point> otherPoints;

    //Checks all the points to see if they are edge vertices / in convex hull
    for (auto point : pointsTemp) {
        bool isInConvexHull = false;

        //Checks if point is in the convex hull
        for (auto convexHullPoint : output) {
            if (point.x == convexHullPoint.x && point.y == convexHullPoint.y) {
                isInConvexHull = true;
                break;
            }
        }

        //Adds points that aren't edge vertices to the new vector
        if (!isInConvexHull) {
            otherPoints.push_back(point);
        }
    }

    //Convex hull requires a minimum of 3 points
    if (output.size() < 3) {
        File << "Convex Hull is not possible" << std::endl;
        File << "\ngraph G {\n";
        //Writes only the points to the file (no edges)
        std::cout << pointsTemp.size();
        for (size_t i = 0; i < pointsTemp.size(); i++) {
            File << "\t" << i << " [label=\"(" << pointsTemp[i].x << "," << pointsTemp[i].y << ")\"];\n";
        }
        File << "}\n";
        return;
    }

    File << "graph G {\n";

    //Writes edge vertices as nodes
    for (size_t i = 0; i < output.size(); i++) {
        File << "\t" << i << " [label=\"(" << output[i].x << "," << output[i].y << ")\"];\n";
    }

    //Draws edges representing the convex hull
    for (size_t i = 0; i < output.size(); i++) {
        size_t nextIndex = (i + 1) % output.size();
        File << "\t" << i << " -- " << nextIndex << " [color=\"blue\"];\n";
    }

    //Writes other points to the dot file
    for (size_t i = 0; i < otherPoints.size(); i++) {
        File << "\t" << i + output.size() << " [label=\"(" << otherPoints[i].x << "," << otherPoints[i].y << ")\"];\n";
    }

    //Fills in convex hull nodes with the color blue
    for (size_t i = 0; i < output.size(); i++) {
        File << "\t" << i << " ";
        File << "[color=\"lightblue\", style=filled];\n";
    }
    File << "}\n";
    File.close();
}










