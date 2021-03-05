#include "/home/arjun/minkowski_addition/set_dilation/include/minkowski_addition.hpp"

int main()
{
    vector<Point> square_1 = get_square(Point(), 1);
    write_shape_to_file("shape_1.txt", square_1);
    vector<Point> circle_2 = get_circle(Point(3, 3), 1, 64);
    write_shape_to_file("shape_2.txt", circle_2);
    vector<Point> result = compute_cspace(circle_2, square_1);
    write_shape_to_file("results.txt", result);
    return 1;
}