#include <iostream>
#include <vector>

class Point{
public:
    Point(int x, int y) : x(x), y(y) {};
    ~Point();
    int x;
    int y;
};

class Convex{
private:
    std::vector<Point> temp;
    std::vector<Point> Pvect;
    std::vector<Point> ConHull;

public:
    Convex(std::vector<Point> pointsvect);
    ~Convex();
    void computeConvex();
    std::vector<Point> getConvex();
    int orientation(Point a, Point b, Point c);
    bool compare(Point a, Point b);
};
