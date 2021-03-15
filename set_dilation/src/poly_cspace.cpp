#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

int main()
{
    float degrees = 90;
    float radians = degrees * PI / 180;
    vector<Point> L_1 = get_L(Point(), 0.75, true, true, 16, radians);
    write_shape_to_file("shape_1.txt", L_1);
    vector<Point> obs_2 = get_obstacle(Point(10, 10), 4, false, true, 128);
    write_shape_to_file("shape_2.txt", obs_2);
    vector<Point> result = compute_cspace_2d(L_1, obs_2);
    write_shape_to_file("poly_results.txt", result);
    return 1;
}
