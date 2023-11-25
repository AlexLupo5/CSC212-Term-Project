#include <iostream>
#include <vector>

class Point{
private:
  int x;
  int y;

public:
  Point(int x, int y);
  ~Point();
}

class Convex{
private:
  Point temp;
  std::vector<Point> Point;
  std::vector<Point> ConHull;

public:
  Convex(std::vector<Point> pointsvect);
  ~Convex();
  int orientation(Point a, Point b, Point c);
  void computeConvex();
  std::vector<Point> getConvex();
  bool compare(Point a, Point b)
};
