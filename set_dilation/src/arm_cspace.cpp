#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

// // CIRCLE
int main()
{
    float joint_1_length = 2;
    float joint_2_length = 2;
    vector<Point> circle_1 = get_circle(Point(2, 2), 0.5, 128);
    // vector<Point> circle_1_angles = calculate_2dof_multiple_joint_angles(Point(), circle_1, {joint_1_length, joint_2_length});
    vector<Point> circle_1_angles = interp_2dof_joint_angles(Point(), circle_1, joint_1_length, joint_2_length, 128);
    Point start_1{2, 1};
    Point goal_1{2, 3};
    Point start_1_angles = calculate_2dof_joint_angles(Point(), start_1, joint_1_length, joint_2_length);
    Point goal_1_angles = calculate_2dof_joint_angles(Point(), goal_1, joint_1_length, joint_2_length);
    write_shape_to_file("arm_results.txt", circle_1_angles);
    write_shape_to_file("angles_1.txt", {start_1_angles});
    write_shape_to_file("angles_2.txt", {goal_1_angles});
    return 1;
}

void triangle_example()
{
    float joint_1_length = 2;
    float joint_2_length = 2;
    vector<Point> triangle_1 = get_triangle(Point(2, 2), 1, true, 4);
    vector<Point> triangle_1_angles = interp_2dof_joint_angles(Point(), triangle_1, joint_1_length, joint_2_length, 128);
    Point goal_1{2, 3};
    Point start_1{2, 1};
    Point goal_1_angles = calculate_2dof_joint_angles(Point(), goal_1, joint_1_length, joint_2_length);
    Point start_1_angles = calculate_2dof_joint_angles(Point(), start_1, joint_1_length, joint_2_length);
    write_shape_to_file("arm_results.txt", triangle_1_angles);
    write_shape_to_file("angles_1.txt", {start_1_angles});
    write_shape_to_file("angles_2.txt", {goal_1_angles});
}

void square_example()
{
    float joint_1_length = 2;
    float joint_2_length = 2;
    vector<Point> square_1 = get_square(Point(2, 2), 1, true, 4);
    vector<Point> square_1_angles = interp_2dof_joint_angles(Point(), square_1, joint_1_length, joint_2_length, 128);
    Point goal_1{2, 3};
    Point start_1{2, 1};
    Point goal_1_angles = calculate_2dof_joint_angles(Point(), goal_1, joint_1_length, joint_2_length);
    Point start_1_angles = calculate_2dof_joint_angles(Point(), start_1, joint_1_length, joint_2_length);
    write_shape_to_file("arm_results.txt", square_1_angles);
    write_shape_to_file("angles_1.txt", {start_1_angles});
    write_shape_to_file("angles_2.txt", {goal_1_angles});
}