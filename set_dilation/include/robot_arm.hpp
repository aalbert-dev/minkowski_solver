#include </home/arjun/minkowski_addition/set_dilation/include/geometry.hpp>

Point calculate_2dof_arm_endpoint(Point ref, float joint_1_length, float joint_2_length, float joint_1_angle, float joint_2_angle)
{
    float c_1 = cos(joint_1_angle);
    float s_1 = sin(joint_1_angle);
    float c_2 = cos(joint_2_angle);
    float s_2 = sin(joint_2_angle);
    float c_sum = c_1 + c_2;
    float s_sum = s_1 + s_2;
    float joint_1_endpoint_x = joint_1_length * c_1;
    float joint_1_endpoint_y = joint_1_length * s_1;
    float joint_2_endpoint_x = joint_1_endpoint_x + joint_2_length * c_1;
    float joint_2_endpoint_y = joint_1_endpoint_y + joint_2_length * s_1;
    return Point(joint_2_endpoint_x, joint_2_endpoint_y);
}

Point calculate_Ndof_arm_endpoint(Point ref, vector<float> joint_lengths, vector<float> joint_angles)
{
    return Point(); // NOT YET IMPLEMENTED
}

vector<float> calculate_joint_angles(Point ref, Point endpoint, float joint_1_length, float joint_2_length)
{
    Point rel_endpoint = endpoint - ref;
    float x = rel_endpoint.x;
    float y = rel_endpoint.y;
    float joint_2_opp_angle = acos((sqr(x) + sqr(y) - sqr(joint_1_length) - sqr(joint_2_length)) / (2 * joint_1_length * joint_2_length));
    float joint_2_angle = PI - joint_2_opp_angle;
    float joint_1_angle = asin((joint_2_length * sin(joint_2_opp_angle)) / (sqr(x) + sqr(y))) + atan2(y, x);
    return {joint_1_angle, joint_2_angle};
}