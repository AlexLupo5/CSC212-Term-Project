#include <iostream>
#include "convexHull.h"
#include <cmath>

const double PI = 3.14159265359; // Variable for PI

convexHull::convexHull(std::string fileName) {
    this->fileName = fileName; // Set fileName of .txt file
    convertToPoint(); //convert the lines on the file to points in a vector (pointsTemp)

    Point points[pointsTemp.size()]; // Creates an array of points with size equal to pointsTemp.size()

    for(int i = 0; i < pointsTemp.size(); i++) {
        points[i].x = pointsTemp[i].x;   ///Sets the points from the vector to the point array.
        points[i].y = pointsTemp[i].y;
    }

    convexHullSolve(points, pointsTemp.size()); //call the convexHullSolve function
}

convexHull::~convexHull(){ //convexHull deconstructor

}

void convexHull::convexHullSolve(Point points[], int size){ //convexHullSolve function
    double lowesty = points[0].y; //set lowesty equal to point[0].y
    int lowestval = 0; //create an index variable for the lowest y value, set the default index to 0
    for (int i = 0; i < size; i++){ //find the lowest y point
        double y = points[i].y;

        if ((y < lowesty) || ((lowesty == y
                               && points[i].x < points[lowestval].x))){ //if the points have the same y point then check for the further away x point
            lowesty = points[i].y; //set the lowesty = to the new lowest y
            lowestval = i; //set the index value
        }
    }

    Point ptemp = points[0]; //create a temp point
    points[0] = points[lowestval]; //swap the lowest y with the first point
    points[lowestval] = ptemp; //swap the first point with the last point

    temp = points[0]; //save the lowest y in a global point

    std::vector <Point> pointSort; //create a new vector to sort the points
    for(int i = 1; i < pointsTemp.size(); i++) { //push back all of the points besides the lowest y into the new vector
        pointSort.push_back(points[i]);
    }

    int num = pointSort.size(); //store the size in an integer variable

    for(int i = 1; i <= num; i++) { //Sort using polar angle
        int ang = 0; //set the angle to 0

        for(int j = 0; j < pointSort.size(); j++) { //

            if (polarAngle(pointSort[ang].x - points[0].x,
                           pointSort[ang].y - points[0].y) ==
                polarAngle(pointSort[j].x - points[0].x,
                           pointSort[j].y - points[0].y)) { //Checks if the next point in reference to the lowest y is equal to the current stored point using polar angle

                if((sqrt(pow(pointSort[ang].x - points[0].x,2) + pow(pointSort[ang].y - points[0].y, 2))) >
                   (sqrt(pow(pointSort[j].x - points[0].x,2) + pow(pointSort[j].y - points[0].y, 2)))) { //Checks which x is further away in reference to lowest y using the distance between points
                    ang = j; //set angle equal to j
                }
            } else {

                if (polarAngle(pointSort[ang].x - points[0].x,
                               pointSort[ang].y - points[0].y) >
                    polarAngle(pointSort[j].x - points[0].x,
                               pointSort[j].y - points[0].y)) { //Checks if the next point in reference to the lowest y is greater than the current stored point using polar angle
                    ang = j; //set angle equal to j
                }
            }
        }
        points[i] = (pointSort[ang]); //add the point to point[i] using the ang as the index of pointSort
        pointSort.erase(pointSort.begin() + ang); //remove that point in point sort
    }

    int index = 1; //set a new variable index to 1
    for (int i = 1; i < size; i++){
        while ((i < size - 1) && (orientation(temp, points[i],points[i + 1]) == 0)){ //increment i until a point has a clockwise or counterclockwise orientation
            i++;
        }
        points[index] = points[i]; //Add points[i] to points[index]
        index = index + 1; //Increment the index by one
    }

    if (index < 3){ //there are not enough points
        return;
    }

    for(int i = 0; i < 3; i++) { //push back points points[1 to 3]
        output.push_back(points[i]);
    }

    for (int i = 3; i < index; i++){ //Increment through rest of points
        while (output.size() > 1 && orientation(Top(output), output[output.size() - 1], points[i]) != 2){
            output.pop_back(); //If angle is a right turn then popback the previous point
        }
        output.push_back(points[i]); //If angle is a left turn then pushback the current point
    }

}

Point convexHull::temp = Point(); //Create a temp variable equal to Point();

Point convexHull::Top(std::vector<Point> &vect){ 
    Point point = vect[vect.size()-1]; //Store the last element in the vector
    vect.pop_back();  //Removes the last element in the vector
    Point answer = vect[vect.size()-1];  //Store the new last element in the vector
    vect.push_back(point); //Put the original last element back onto the top of the vector
    return answer; //return top element
}

double convexHull::polarAngle(double x, double y) { //Returns the polarAngle of the given (x,y) coordinates
    return std::atan2(y, x) * (180.0 / PI);
}

double convexHull::orientation(Point point1, Point point2, Point point3){ //Returns the orientation wether its collineark, clockwise, or counter, clockwise
    double orient = (point2.y - point1.y) * (point3.x - point2.x)
                    - (point2.x - point1.x) * (point3.y - point2.y); //orientation equation

    if (orient >= 0) {
        //Clockwise
        if (orient > 0){
            return 1;
        }
        //Collinear
        else {
            return 0;
        }
    }
        //Counterclockwise
    else{
        return 2;
    }
}

void convexHull::convertToPoint() { //convertToPoint function
    //Reads through the inputFile and puts all x coordinates into
    //points.x vector and all y coordinates in points.y vector
    std::ifstream infile(fileName);
    std::string line;
    std::string x;

    while (getline(infile, line)) {
        std::stringstream strLine(line);
        double tempx = 0;
        double tempy = 0;
        while (strLine >> x) {                    ///Reads through the file and takes in all x and y coordinates
            std::string temp = "";       

            int i = 1;
            while (x[i] != ',') {            ///Once a comma is reached, we know that it is time to add the x coordinate to the temp str w/o including the comma
                temp += x[i];
                i++;
            }
            tempx = std::stod(temp);            ///Converts the string value to a double
            i++;
            temp.clear();                    ///Clear the temp string to allocate space for storing y coordinates 

            while (x[i] != ')') {            ///Once a closed parenthesis is reached we know the previous value is the y coordinate so the while loop breaks
                temp += x[i];            ///Stores y coord. in temp str
                i++;
            }
            tempy = std::stod(temp);        ///Converts str value y to double
        }
        pointsTemp.push_back({tempx, tempy});    ////Pushes that specific x,y coordinate into the temp vec declared in .h
    }
}

void convexHull::print() {
    if(pointsTemp.size() < 3) {
        std::cout << "Requires 3 or more points" << std::endl;
        std::cout << "Cannot construct Convex Hull" << std::endl;            ///To construct a convex hull, oriented as a polygonal structure requires atleast 3 points
        return;
    }

    if(output.empty()) {
        std::cout << "No Convex Hull points" << std::endl;
        std::cout << "Cannot construct Convex Hull" << std::endl;        ///If no points are given convex hull cannot be created 
        return;
    }

    std::vector<Point> out = output;

    while (out.size() > 0){
        Point point = out[out.size()-1];                        ///Prints out each point
        std::cout << "(" << point.x << ", " << point.y <<")\n";
        out.pop_back();
    }
}

void convexHull::dot(std::string outputName) {
    std::vector<Point> out = output;
    std::ofstream File(outputName); // Create or open a dot file named "output.dot"

    if (!File.is_open()) { //If the file cannot be open output the message
        std::cout << "Could not open the dot file." << std::endl;
    }
    else {
        while (out.size() > 0) { //Traverse through each point and puts each point into the dot file with the form (x,y)
            Point point = out[out.size() - 1];
            File << "(" << point.x << "," << point.y << ")";
            if (out.size() > 1) {
                File << "\n";
            }
            out.pop_back();
        }
    }
}

void convexHull::nonSFMLDot() {
    //Creating a dot file named "convexHullGraphviz.dot"
    std::ofstream File("convexHullGraphviz.dot");

    if (!File.is_open()) {
        std::cout << "Could not open the dot file." << std::endl;
    }

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
        File << "graph G {\n";
        //Writes only the points to the file (no edges)
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
