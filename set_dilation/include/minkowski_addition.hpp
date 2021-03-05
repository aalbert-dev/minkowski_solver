#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Point
{
  float x, y, z;
  Point(){};
  Point(float x, float y) : x(x), y(y), z(0){};
  Point(float x, float y, float z) : x(x), y(y), z(z){};
  bool operator==(const Point &other) { return x == other.x && y == other.y && z == other.z; }
  Point operator+(const Point &other) { return Point(x + other.x, y + other.y, z + other.z); }
  Point operator-(const Point &other) { return Point(x - other.x, y - other.y, z - other.z); }
};

vector<Point> compute_sum(vector<Point> a, vector<Point> b)
{
  vector<Point> c;
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      c.push_back(a.at(i) + b.at(j));
    }
  }
  return c;
}

void write_shape_to_file(string f_name, vector<Point> shape)
{
  ofstream results_file(f_name);
  for (int i = 0; i < shape.size(); i++)
  {
    Point curr_point = shape.at(i);
    results_file << curr_point.x << ", " << curr_point.y << ", " << curr_point.z << "\n";
  }
  results_file.close();
}