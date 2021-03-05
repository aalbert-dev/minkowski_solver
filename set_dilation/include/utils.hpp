#include <iostream>
#include <fstream>
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

vector<Point> compute_cspace(vector<Point> a, vector<Point> b)
{
  vector<Point> sum_result;
  vector<Point> diff_result;
  if (a.size() > b.size())
  {
    sum_result = compute_sum(a, b);
    diff_result = compute_diff(a, b);
  }
  else
  {
    sum_result = compute_sum(b, a);
    diff_result = compute_diff(b, a);
  }
  sum_result.insert(sum_result.end(), diff_result.begin(), diff_result.end());
  return sum_result;
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
