#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

int main()
{
    // vector<Point> square_1 = get_square(Point(), 1, true, 8);
    // write_shape_to_file("shape_1.txt", square_1);
    vector<Point> triangle_1 = get_triangle(Point(1, 1), 1, true, 2);
    write_shape_to_file("shape_1.txt", triangle_1);
    vector<Point> obs_2 = get_obstacle(Point(4, 4), 4, 128);
    write_shape_to_file("shape_2.txt", obs_2);
    vector<Point> result = compute_cspace(triangle_1, obs_2);
    write_shape_to_file("results.txt", result);
    return 1;
}