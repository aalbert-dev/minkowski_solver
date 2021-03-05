#include "../include/minkowski_addition.hpp"

int main()
{
    vector<Point> square_1 = get_square(Point(), 1);
    write_shape_to_file("shape_1.txt", square_1);
    vector<Point> square_2 = get_square(Point(2, 2), 1);
    write_shape_to_file("shape_2.txt", square_2);
    vector<Point> result = compute_sum(square_1, square_2);
    write_shape_to_file("results.txt", result);
    return 1;
}