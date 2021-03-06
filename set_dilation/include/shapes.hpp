#include </home/arjun/minkowski_addition/set_dilation/include/robot_arm.hpp>

vector<Point> get_triangle(Point ref, float size, bool interp = false, int num_points = 2)
{
    vector<Point> triangle;
    triangle.push_back(ref + Point(0, 0));
    triangle.push_back(ref + Point(0, size));
    triangle.push_back(ref + Point(size / 2, size / 2));
    if (interp)
        return interp_lines(triangle, num_points);
    return triangle;
}

vector<Point> get_square(Point ref, float size, bool interp = false, int num_points = 2)
{
    vector<Point> square;
    square.push_back(ref + Point(0, 0));
    square.push_back(ref + Point(0, size));
    square.push_back(ref + Point(size, size));
    square.push_back(ref + Point(size, 0));
    if (interp)
        return interp_lines(square, num_points);
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

vector<Point> get_obstacle(Point ref, float size, bool interp = false, int num_points = 2)
{
    vector<Point> corner_pts;
    corner_pts.push_back(ref + Point(0, 0));
    corner_pts.push_back(ref + Point(0, size));
    corner_pts.push_back(ref + Point(size * 0.5, size));
    corner_pts.push_back(ref + Point(size * 0.5, size * 0.5));
    corner_pts.push_back(ref + Point(size * 2, size * 0.5));
    corner_pts.push_back(ref + Point(size * 2, size * 2.5));
    corner_pts.push_back(ref + Point(size * 0.5, size * 2.5));
    corner_pts.push_back(ref + Point(size * 0.5, size * 2));
    corner_pts.push_back(ref + Point(0, size * 2));
    corner_pts.push_back(ref + Point(0, size * 3));
    corner_pts.push_back(ref + Point(size * 2.5, size * 3));
    corner_pts.push_back(ref + Point(size * 2.5, 0));
    if (interp)
        return interp_lines(corner_pts, num_points);
    return corner_pts;
}