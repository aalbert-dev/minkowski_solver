#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Point
{
  float x, y;
  Point(){};
  Point(float x, float y) : x(x), y(y){};
  bool operator==(const Point &other) { return x == other.x && y == other.y; }
  Point operator+(const Point &other) { return Point(x + other.x, y + other.y); }
  Point operator-(const Point &other) { return Point(x - other.x, y - other.y); }
};

vector<Point> compute_sum(vector<Point> a, vector<Point> b)
{
  vector<Point> c;
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      Point curr_a = a.at(i);
      Point curr_b = b.at(j);
      Point curr_c = curr_a + curr_b;
      c.push_back(curr_c);
    }
  }
  return c;
}

void write_results(vector<Point> result)
{
  ofstream results_file("results.txt");
  for (int i = 0; i < result.size(); i++)
  {
    Point curr_point = result.at(i);
    results_file << curr_point.x << ", " << curr_point.y << "\n";
  }
  results_file.close();
}