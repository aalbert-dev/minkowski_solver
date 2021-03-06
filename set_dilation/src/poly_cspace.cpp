#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

int main()
{
    vector<Point> square_1 = get_square(Point(), 1, true, 8);
    write_shape_to_file("shape_1.txt", square_1);
    vector<Point> obs_2 = get_obstacle(Point(10, 10), 4, true, 128);
    write_shape_to_file("shape_2.txt", obs_2);
    vector<Point> result = compute_cspace(square_1, obs_2, true);
    write_shape_to_file("poly_results.txt", result);
    return 1;
}