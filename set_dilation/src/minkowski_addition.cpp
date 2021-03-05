#include "../include/minkowski_addition.hpp"

int main()
{
    // vector<Point> triangle_1;
    // triangle_1.push_back(Point(1, 0));
    // triangle_1.push_back(Point(0, 1));
    // triangle_1.push_back(Point(0, -1));
    // write_shape_to_file("shape_1.txt", triangle_1);

    // vector<Point> triangle_2;
    // triangle_2.push_back(Point(0, 0));
    // triangle_2.push_back(Point(1, 1));
    // triangle_2.push_back(Point(1, -1));
    // write_shape_to_file("shape_2.txt", triangle_2);

    // vector<Point> result = compute_sum(triangle_2, triangle_1);
    // write_shape_to_file("results.txt", result);
    // vector<Point> line_1;
    // line_1.push_back(Point(0, 0));
    // line_1.push_back(Point(0, 1));
    // write_shape_to_file("shape_2.txt", line_1);

    // vector<Point> line_2;
    // line_2.push_back(Point(2, 2));
    // line_2.push_back(Point(3, 3));
    // write_shape_to_file("shape_1.txt", line_2);

    // vector<Point> result = compute_sum(line_1, line_2);
    // write_shape_to_file("results.txt", result);
    vector<Point> square_1;
    square_1.push_back(Point(0, 0));
    square_1.push_back(Point(0, 1));
    square_1.push_back(Point(1, 1));
    square_1.push_back(Point(1, 0));
    write_shape_to_file("shape_1.txt", square_1);

    vector<Point> square_2;
    square_2.push_back(Point(1, 1));
    square_2.push_back(Point(1, 2));
    square_2.push_back(Point(2, 2));
    square_2.push_back(Point(2, 1));
    write_shape_to_file("shape_2.txt", square_2);

    vector<Point> result = compute_sum(square_1, square_2);
    write_shape_to_file("results.txt", result);
    return 1;
}