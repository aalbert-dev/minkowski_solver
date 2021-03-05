#include <vector>
#include <math.h>

#define PI M_PI

using namespace std;

struct Point
{
    float x, y, z;
    Point() : x(0), y(0){};
    Point(float x, float y) : x(x), y(y), z(0){};
    Point(float x, float y, float z) : x(x), y(y), z(z){};
    bool operator==(const Point &other) { return x == other.x && y == other.y && z == other.z; }
    Point operator+(const Point &other) { return Point(x + other.x, y + other.y, z + other.z); }
    Point operator-(const Point &other) { return Point(x - other.x, y - other.y, z - other.z); }
};

Point rotate(Point a, float angle)
{
    float c = cos(angle);
    float s = sin(angle);
    float x = a.x * c - a.y * s;
    float y = a.x * s - a.y * c;
    return Point(x, y);
}

Point rotate_about(Point a, Point b, float angle)
{
    return rotate(a - b, angle) + b;
}

vector<Point> rotate_vector(vector<Point> pts, Point ref, float angle)
{
    vector<Point> new_pts;
    for (int i = 0; i < pts.size(); i++)
    {
        Point cur_point = pts.at(i);
        Point new_point = rotate_about(cur_point, ref, angle);
        new_pts.push_back(new_point);
    }
    return new_pts;
}
