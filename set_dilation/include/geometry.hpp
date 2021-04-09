#include <vector>
#include <math.h>
#include <limits>

#define PI M_PI

#define SQUARED(x) ((x) * (x))

using namespace std;

// Numeric limits
float f_max = numeric_limits<float>::max();
float f_min = numeric_limits<float>::min();

/**
 * Class to represent a point in 3D space.
 * Contains comparison and vector math operators.
 **/
struct Point
{
    float x, y, z;
    Point() : x(0), y(0){};
    Point(float x, float y) : x(x), y(y), z(0){};
    Point(float x, float y, float z) : x(x), y(y), z(z){};
    bool operator==(const Point &other) { return x == other.x && y == other.y && z == other.z; }
    bool operator!=(const Point &other) { return x != other.x || y != other.y; }
    Point operator+(const Point &other) { return Point(x + other.x, y + other.y, z + other.z); }
    Point operator-(const Point &other) { return Point(x - other.x, y - other.y, z - other.z); }
};

inline float sqr(float n)
{
    return pow(n, 2);
}

inline float distance(Point a, Point b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

/**
 * Method to rotate a point by an angle with 
 * respect to the origin.
 * Returns the transformed angle.
 **/
Point rotate(Point a, float angle)
{
    float c = cos(angle);
    float s = sin(angle);
    float x = a.x * c - a.y * s;
    float y = a.y * c + a.x * s;
    return Point(x, y);
}

/**
 * Method to rotate point A about point B by 
 * an angle (radians) in 3D space.
 * Does a linear transformation from A to the origin by 
 * A - B = A'
 * A' is then rotated and transformed back to the 
 * frame of B.
 * Returns A' + B
 **/
Point rotate_about(Point a, Point b, float angle)
{
    return rotate(a - b, angle) + b;
}

/**
 * Rotates a vector of points about a single reference point.
 * Returns the resulting vector. 
 **/
vector<Point> rotate_vector(vector<Point> pts, Point ref, float angle)
{
    if (angle == 0.0)
        return pts;
    vector<Point> new_pts;
    for (int i = 0; i < pts.size(); i++)
    {
        Point cur_point = pts.at(i);
        Point new_point = rotate_about(cur_point, ref, angle);
        new_pts.push_back(new_point);
    }
    return new_pts;
}

/**
 * Find the minimum and maximum X and Y value of 
 * a vector of point.
 * Returns the result as a vector of the maxima/minima.
 **/
vector<float> get_ranges(vector<Point> pts)
{
    float min_x = f_max;
    float max_x = f_min;
    float min_y = f_max;
    float max_y = f_min;
    for (auto &pt : pts)
    {
        if (pt.x < min_x)
            min_x = pt.x;
        if (pt.x > max_x)
            max_x = pt.x;
        if (pt.y < min_y)
            min_y = pt.y;
        if (pt.y > max_y)
            max_y = pt.y;
    }
    return vector<float>{min_x, max_x, min_y, max_y};
}

/**
 * Transforms a vector of points offset from the origin 
 * to be approximately symmetrical about the origin with 
 * a fixed reference frame.
 * Returns the centered vector of points.
 **/
vector<Point> center_at_zero(vector<Point> pts)
{
    vector<float> ranges = get_ranges(pts);
    float min_x = ranges[0];
    float max_x = ranges[1];
    float min_y = ranges[2];
    float max_y = ranges[3];

    Point center_pt = Point((max_x - min_x) / 2, (max_y - min_y) / 2);
    vector<Point> new_pts;
    for (auto &pt : pts)
    {
        new_pts.push_back(center_pt - pt);
    }
    return new_pts;
}

/**
 * Rotates a vector of points offset from the origin by an 
 * angle (radians) then does a linear transformation to 
 * the origin centering the points.
 * Returns the centered rotated vector of points.
 **/
vector<Point> center_and_rotate(vector<Point> pts, float angle)
{
    vector<float> ranges = get_ranges(pts);
    float min_x = ranges[0];
    float max_x = ranges[1];
    float min_y = ranges[2];
    float max_y = ranges[3];
    Point center_pt = Point((max_x - min_x) / 2, (max_y - min_y) / 2);
    vector<Point> rotated_pts = rotate_vector(pts, center_pt, angle);
    vector<Point> centered_pts = center_at_zero(rotated_pts);
    return centered_pts;
}

/**
 * Interpolates a vector of N (num points) points between 
 * point A and point B.
 * Returns the vector of N points including A and B.
 **/
vector<Point> interpolate(Point a, Point b, int num_points)
{

    vector<Point> pts;
    float angle = atan2((b.y - a.y), (b.x - a.x));
    float dist = distance(a, b);
    float step = dist / num_points;
    for (int i = 0; i < num_points + 1; i++)
    {
        float x = a.x + step * i * cos(angle);
        float y = a.y + step * i * sin(angle);
        pts.push_back(Point(x, y));
    }
    return pts;
}

/**
 * Interpolates a vector of corner points (verticies) of a polygon
 * into a vector of points representing the edge points of the polygon.
 * Returns the interpolated polygon as a vector of points.
 **/
vector<Point> interp_lines(vector<Point> pts, int num_points, int backtrace = 0)
{
    vector<Point> interp_pts;
    for (int i = 0; i < pts.size() - 1 + backtrace; i++)
    {
        Point cur_point = pts.at(i);
        Point next_point = pts.at((i + 1) % pts.size());
        vector<Point> new_pts;
        new_pts = interpolate(cur_point, next_point, num_points);
        interp_pts.insert(interp_pts.end(), new_pts.begin(), new_pts.end());
    }
    return interp_pts;
}

/**
 * Interpolates a vector of N (num points) angles
 * between angle A and angle B.
 * Returns the vector of N angles.
 **/
vector<float> interp_angles(float a, float b, int num_angles)
{
    float angle_step = (b - a) / num_angles;
    vector<float> angles;
    for (int i = 0; i < num_angles; i++){
        angles.push_back(a + angle_step * i);
    }
    return angles;
} 