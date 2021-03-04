#include <iostream>
#include <vector>
#include <graphics.h>

using namespace std;

struct Point
{
  float x, y;
  Point(float x, float y) : x(x), y(y){};
  bool operator==(const Point &other) { return x == other.x && y == other.y; }
  Point(){};
};