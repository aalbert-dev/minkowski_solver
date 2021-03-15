#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/shapes.hpp"

using namespace std;

string data_folder = "/home/arjun/minkowski_addition/set_dilation/data/";

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

vector<Point> compute_cspace_2d(vector<Point> a, vector<Point> b, bool negative = true)
{
  vector<Point> sum_result;
  vector<Point> diff_result;
  if (a.size() > b.size())
  {

    if (negative)
    {
      diff_result = compute_diff(a, b);
    }
    else
    {
      sum_result = compute_sum(a, b);
    }
  }
  else
  {

    if (negative)
    {
      diff_result = compute_diff(b, a);
    }
    else
    {
      sum_result = compute_sum(b, a);
    }
  }
  if (negative)
  {
    return diff_result;
  }
  else
  {
    return sum_result;
  }
}

// vector<Point> compute_cspace_3d(vector<Point> a, vector<Point> b, vector<float> rots)
// {
//   vector<Point> results;
//   for (auto &rot : rots)
//   {
//     vector<Point> sum_result;
//     sum_result = compute_cspace_2d(a, b);
//     for (int i = 0; i < sum_result.size(); i++)
//     {
//       sum_result.at(i).z = rot;
//     }
//     results.insert(sum_result.begin(), sum_result.end(), results.end());
//   }
//   return results;
// }

inline vector<Point> append(vector<Point> v1, vector<Point> v2)
{
  v1.insert(v1.end(), v2.begin(), v2.end());
  return v1;
}