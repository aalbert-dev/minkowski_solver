#include "../include/minkowski_addition.hpp"

int main()
{
    vector<Point> triangle_1;
    triangle_1.push_back(Point(1, 0));
    triangle_1.push_back(Point(0, 1));
    triangle_1.push_back(Point(0, -1));

    vector<Point> triangle_2;
    triangle_2.push_back(Point(0, 0));
    triangle_2.push_back(Point(1, 1));
    triangle_2.push_back(Point(1, -1));

    vector<Point> result = compute_sum(triangle_1, triangle_2);
    write_results(result);
    return 1;
}