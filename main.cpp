#include "convexHull.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/*input file should be formatted as shown below
 *(x1,y1)
 *(x2,y2)
 *(x3,y3)
 */

int main(int argc, char*argv[]) {

        convexHull shape((std::string(argv[1]))); //Creates an object of convexHull, in provided main.cpp object is called shape
        shape.print(); //Prints the convexHull output to terminal
        shape.dot(); //Prints the convexHull output to a .dot file

    return 0;
}