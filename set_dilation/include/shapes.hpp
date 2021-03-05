#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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

vector<Point> get_triangle(Point ref, float size)
{
    vector<Point> triangle;
    triangle.push_back(ref + Point(0, 0));
    triangle.push_back(ref + Point(0, size));
    triangle.push_back(ref + Point(size / 2, size / 2));
    return triangle;
}

vector<Point> get_square(Point ref, float size)
{
    vector<Point> square;
    square.push_back(ref + Point(0, 0));
    square.push_back(ref + Point(0, size));
    square.push_back(ref + Point(size, size));
    square.push_back(ref + Point(size, 0));
    return square;
}

vector<Point> get_obstacle(Point ref, float size)
{
    vector<Point> square;
    square.push_back(ref + Point(0, 0));
    square.push_back(ref + Point(0, size));
    square.push_back(ref + Point(size, size));
    square.push_back(ref + Point(size, 0));
    return square;
}
