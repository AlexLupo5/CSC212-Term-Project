void convexHull::convertToPoint() {
    std::ifstream infile(fileName);
    std::string line;
    std::string x;

    while (getline(infile, line)) {
        std::stringstream strLine(line);
        double tempx = 0;
        double tempy = 0;

        while (strLine >> x) {
            std::string temp = "";    ///Collects all x and y coordinates

            int i = 1;
            while (x[i] != ',') {    ///If a comma is reached break, and store x coord
                temp += x[i];
                i++;
            }
            tempx = std::stod(temp);    ///Convert to double
            i++;
            temp.clear();    ///Clear str to store y values

            while (x[i] != ')') { ///If closed parenthesis is reached break, store y coord
                temp += x[i];
                i++;
            }
            tempy = std::stod(temp);    ///Convert to double
        }

        pointsTemp.push_back({tempx + 1, tempy + 1});    ///Pushes into vec which will then be used by the array to store all input points.
    }  
}

void convexHull::print() {
    if (pointsTemp.size() < 3) {
        std::cout << "Must Input Atleast 3 Points" << std::endl;        ///Condition; Atleast 3 points to form convex hull
        std::cout << "Therefore, unable to form Convex Hull" << std::endl;
        return;
    }

    if (output.empty()) {
        std::cout << "No Convex Hull points were provided" << std::endl;      ///Points > 3 must be provided, accounts for no input
        std::cout << "Therefore, unable to form Convex Hull" << std::endl;
        return;
    }

    std::vector<Point> out = output;

  ///Iterates through to print out each point
    for (const auto& point : out) {
        std::cout << "(" << point.x + 1 << ", " << point.y + 1 << ")\n";  // Modify maybe? an approach to printing points out... 
    }
}
