#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/shapes.hpp"
#include <eigen3/Eigen/Dense>
#include <algorithm>

using namespace std;

string data_folder = "/home/arjun/minkowski_addition/set_dilation/data/";

/**
 * Writes a vector of points as csv coordinates to a path.
 **/
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

inline void print_point_vector(vector<Point> a)
{
  for (auto &p : a)
  {
    cout << p.x << " " << p.y << endl;
  }
  cout << endl;
}

inline void print_matrix_(Eigen::MatrixXf a)
{
  for (int i = 0; i < a.cols(); i++)
  {
    for (int j = 0; j < a.rows(); j++)
    {
      cout << a(j, i) << ", ";
    }
    cout << endl;
  }
  cout << endl;
}

/**
 * 
 **/
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

Eigen::MatrixXf point_vector_to_matrix(vector<Point> a)
{
  Eigen::MatrixXf points(a.size(), 2);
  for (int i = 0; i < a.size(); i++)
  {
    points(i, 0) = a.at(i).x;
    points(i, 1) = a.at(i).y;
  }
  return points;
}

inline void shift_vector_right(vector<Point> &a)
{
  rotate(a.begin(), a.begin() + 1, a.end());
}

void append_matricies(Eigen::MatrixXf &a, Eigen::MatrixXf b)
{
  Eigen::MatrixXf c = a;
  //cout << a.rows() << "--" << a.cols() << endl;
  a.resize(a.rows(), a.cols() + b.cols());
  // cout << a << endl;
  // cout << b << endl;
  // cout << endl;
  // cout << c << endl;
  // int x; cin >> x;
  // cout << a.cols() << endl;
  // cout << a.rows() << endl;
  // int y;
  // cin >> y;
  for (int i = 0; i < c.cols() + b.cols(); i++)
  {
    for (int j = 0; j < c.rows(); j++)
    {
      cout << j << ", " << i << endl;
      if (i >= c.cols())
      {
        //a(j, i) = b(j - c.cols(), i);
      }
      else
      {
        a(j, i) = c(j, i);
        //cout << a(j, i);
      }
    }
  }
  //print_matrix_(a);
  //cout << a << endl;
  int z;
  cin >> z;
}

vector<Point> fast_sum(vector<Point> a, vector<Point> b)
{

  Eigen::MatrixXf m_b = point_vector_to_matrix(b);
  Eigen::MatrixXf a_init = point_vector_to_matrix(a);
  Eigen::MatrixXf sum_init = a_init + m_b;
  for (int i = 1; i < a.size(); i++)
  {
    shift_vector_right(a);
    Eigen::MatrixXf m_a = point_vector_to_matrix(a);
    Eigen::MatrixXf m_s = m_a + m_b;
    append_matricies(sum_init, m_s);
  }
  // convert MatrixXf to vector<point>
  return {Point()};
}

vector<Point> compute_cspace_2d_fast(vector<Point> a, vector<Point> b)
{
  if (a.size() > b.size())
  {
    return fast_sum(a, b);
  }
  else
  {
    return fast_sum(b, a);
  }
}

vector<Point> compute_cspace_3d(vector<vector<Point>> a, vector<Point> b, vector<float> rots)
{
  vector<Point> results;
  for (int i = 0; i < a.size(); i++)
  {
    vector<Point> result = compute_cspace_2d(a[i], b);
    for (int j = 0; j < result.size(); j++)
    {
      result.at(j).z = rots[i];
    }
    results.insert(results.end(), result.begin(), result.end());
  }
  return results;
}

inline vector<Point> append(vector<Point> v1, vector<Point> v2)
{
  v1.insert(v1.end(), v2.begin(), v2.end());
  return v1;
}