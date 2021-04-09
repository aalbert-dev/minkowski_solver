#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

int main()
{
    float degrees = 0;
    float radians = degrees * PI / 180;
    vector<Point> triangle_1 = {Point(1,0), Point(0,1), Point(0,-1)};
    vector<Point> triangle_2 = {Point(0,0), Point(1,1), Point(1,-1)};
    vector<Point> result = fast_sum(triangle_1, triangle_2);
    return 1;
}

// int main()
// {
//     float degrees = 0;
//     float radians = degrees * PI / 180;
//     vector<Point> L_1 = get_L(Point(), 0.75, true, true, 16, radians);
//     write_shape_to_file("shape_1.txt", L_1);
//     vector<Point> obs_2 = get_obstacle(Point(10, 10), 4, false, true, 128);
//     write_shape_to_file("shape_2.txt", obs_2);
//     vector<Point> result = compute_cspace_2d(L_1, obs_2);
//     write_shape_to_file("poly_results.txt", result);
//     return 1;
// }

// int main()
// {
//     float degrees = 90;
//     float radians = degrees * PI / 180;
//     vector<Point> circle = get_circle(Point(), 1.75, 128);
//     write_shape_to_file("shape_1.txt", circle);
//     vector<Point> obs_2 = get_obstacle(Point(10, 10), 4, false, true, 128);
//     write_shape_to_file("shape_2.txt", obs_2);
//     vector<Point> result = compute_cspace_2d(circle, obs_2);
//     write_shape_to_file("poly_results.txt", result);
//     return 1;
// }