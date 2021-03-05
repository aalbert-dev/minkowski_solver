#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../include/shapes.hpp"

using namespace std;

string data_folder = "/home/arjun/minkowski_addition/set_dilation/data/";

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

vector<Point> compute_diff(vector<Point> a, vector<Point> b)
{
  vector<Point> c;
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      c.push_back(a.at(i) - b.at(j));
    }
  }
  return c;
}

void write_shape_to_file(string f_name, vector<Point> shape)
{
  ofstream results_file(data_folder + f_name);
  for (int i = 0; i < shape.size(); i++)
  {
    Point curr_point = shape.at(i);
    results_file << curr_point.x << ", " << curr_point.y << ", " << curr_point.z << "\n";
  }
  results_file.close();
}
