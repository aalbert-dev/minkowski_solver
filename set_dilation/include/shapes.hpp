#include </home/arjun/minkowski_addition/set_dilation/include/geometry.hpp>

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

vector<Point> get_circle(Point ref, float radius, int num_points)
{
    vector<Point> circle;
    float angle_increment = (2 * PI) / num_points;
    for (int i = 0; i < num_points + 1; i++)
    {
        circle.push_back(ref + Point(cos(angle_increment * i) * radius, sin(angle_increment * i) * radius));
    }
    return circle;
}

vector<Point> get_obstacle(Point ref, float size)
{
    vector<Point> obs;
    return obs;
}