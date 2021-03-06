#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

int main()
{

    vector<Point> circle_1 = get_circle(Point(2, 2), 0.5, 128);
    vector<Point> circle_1_angles = calculate_multiple_joint_angles(Point(), circle_1, {2, 2});
    Point goal_1 {2, 3};
    Point start_1 {2, 1};
    Point goal_1_angles = calculate_joint_angles(Point(), goal_1, 2, 2);
    Point start_1_angles = calculate_joint_angles(Point(), start_1, 2, 2);
    write_shape_to_file("arm_results.txt", circle_1_angles);
    write_shape_to_file("angles_1.txt", {start_1_angles});
    write_shape_to_file("angles_2.txt", {goal_1_angles});
    return 1;
}