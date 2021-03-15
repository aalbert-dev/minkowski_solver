#include <vector>
#include <math.h>
#include <limits>

#define PI M_PI

#define SQUARED(x) ((x) * (x))

using namespace std;

float f_max = numeric_limits<float>::max();
float f_min = numeric_limits<float>::min();

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

Point rotate(Point a, float angle)
{
    float c = cos(angle);
    float s = sin(angle);
    float x = a.x * c - a.y * s;
    float y = a.y * c + a.x * s;
    return Point(x, y);
}

Point rotate_about(Point a, Point b, float angle)
{
    return rotate(a - b, angle) + b;
}

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

vector<float> interp_angles(float a, float b, int num_angles)
{
    float angle_step = (b - a) / num_angles;
    vector<float> angles;
    for (int i = 0; i < num_angles; i++){
        angles.push_back(a + angle_step * i);
    }
    return angles;
} 