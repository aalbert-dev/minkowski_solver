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

vector<Point> get_obstacle(Point ref, float size, bool correct_center = false, bool interp = false, int num_points = 2)
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
    vector<Point> center_corner_pts = corner_pts;
    if (correct_center)
    {
        center_corner_pts = center_at_zero(corner_pts);
    }
    if (interp)
        return interp_lines(center_corner_pts, num_points, 1);
    return center_corner_pts;
}

vector<Point> get_L(Point ref, float size, bool correct_center = false, bool interp = false, int num_points = 2, float rot = 0.0)
{
    vector<Point> corner_pts;
    corner_pts.push_back(ref + Point(0, 0));
    corner_pts.push_back(ref + Point(0, size * 6));
    corner_pts.push_back(ref + Point(size * 2, size * 6));
    corner_pts.push_back(ref + Point(size * 2, size * 2));
    corner_pts.push_back(ref + Point(size * 4, size * 2));
    corner_pts.push_back(ref + Point(size * 4, 0));
    vector<Point> center_corner_pts = corner_pts;
    if (correct_center)
    {
        center_corner_pts = center_and_rotate(corner_pts, rot);
    }
    if (interp)
        return interp_lines(center_corner_pts, num_points, 1);
    return center_corner_pts;
}

vector<Point> get_ref_square()
{
    vector<Point> corner_pts;
    corner_pts.push_back(Point(-1, -1));
    corner_pts.push_back(Point(1, -1));
    corner_pts.push_back(Point(1, 1));
    corner_pts.push_back(Point(-1, 1));
    return corner_pts;
}