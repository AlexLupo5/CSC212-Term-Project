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
    Point temp;
    std::vector<Point> Pvect;
    std::vector<Point> ConHull;

public:
    Convex(std::vector<Point> pointsvect);
    ~Convex();
    void computeConvex();
    std::vector<Point> getConvex();
    int orientation(std::vector<Point> a, std::vector<Point> b, std::vector<Point> c);
    bool compare(std::vector<Point> a, std::vector<Point> b);
};
