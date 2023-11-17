#include <iostream>
#include <vector>

class Point{
private:
  int x;
  int y;

public:
  Point(int x, int y);
  ~Point();
  bool compare(int x1, int y1, int x2, int y2);

}

class Convex{
private:
  std::vector<int> point;

public:
  Convex(std::vector<int> point);
  ~Convex();
  int orientation(std::vector<int> point);
  int computeConvex(std::veector<int> point);

};
