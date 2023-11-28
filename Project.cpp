#include <iostream>
#include "Project.h"

//Constructor
Convex::Convex(std::vector<Point> pointsvect){
    this->Pvect = pointsvect;
}

Convex::~Convex(){

}

void Convex::computeConvex(){
    //If there are less than three points then return
    //Because you need at least three points for Convex Hull
    if (this->Pvect.size() < 3){
        return;
    }

    //Find the point that has the lowest or leftmost y-coordinate
    int small = 0;
    for (int i = 1; i < this->Pvect.size(); i++){
        if (this->Pvect[i].y < this->Pvect[small].y || (this->Pvect[i].y
                < this->Pvect[small].y && this->Pvect[i].x < this->Pvect[small].x)){
            small = i;
        }
    }

    //Swap the lowest and first point
    std::swap(this->Pvect[0], this->Pvect[small]);

    //Sort the other point based on polar angle
    temp[0] = this->Pvect[0];
    std::sort(this->Pvect.begin() + 1, this->Pvect.end(), compare);

    //Create the convex hull with the three first points
    ConHull.push_back(this->Pvect[0]);
    ConHull.push_back(this->Pvect[1]);
    ConHull.push_back(this->Pvect[2]);

    //Compute the rest of the points
    for (int i = 3; i < this->Pvect.size(); i++){
        while(orientation(ConHull[ConHull.size() - 2], ConHull[ConHull.size() - 1],
                          this->Pvect[i]) != 2){
            ConHull.pop_back();
        }
        ConHull.push_back();
    }
}

int Convex::orientation(std::vector<Point> a, std::vector<Point> b, std::vector<Point> c){
    //Compute equation for orientation
    int numb = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    //Collinear
    if (numb == 0){
        return 0;
    }
    //Clockwise
    if (numb > 0){
        return 1;
    }
        //Counterclockwise
    else {
        return 2;
    }
}

//Returns the Convex Hull
std::vector<Point> Convex::getConvex(){
    return ConHull;
}

bool Convex::compare(std::vector<Point> a, std::vector<Point> b){
    //Check orientation
    int check = orientation(temp, a, b);

    if (check == 0){
        return (temp.x + temp.y) < (a.x + a.y);
    }

    //Counterclockwise sort
    return check == 2;
}



      
