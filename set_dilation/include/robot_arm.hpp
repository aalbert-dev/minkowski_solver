#include </home/arjun/minkowski_addition/set_dilation/include/geometry.hpp>

class Arm
{
public:
    Arm(Point origin, float joint_1_length, float joint_2_length, vector<float> joint_1_range, vector<float> joint_2_range);
    bool activate(float joint_1_angle, float joint_2_angle);
    Point calculate_new_endpoint(float joint_1_angle, float joint_2_angle);
    bool move_joint_1(float angle);
    bool move_joint_2(float angle);
    Point origin;
    Point elbowpoint;
    Point endpoint;
    float joint_1_length;
    float joint_2_length;
    vector<Point> joint_1_pts;
    vector<Point> joint_2_pts;
    float joint_1_start_angle;
    float joint_1_end_angle;
    float joint_2_start_angle;
    float joint_2_end_angle;

private:
    bool interp;
};

Arm::Arm(Point origin, float joint_1_length, float joint_2_length, vector<float> joint_1_range, vector<float> joint_2_range)
{
    // Arm::origin = origin;
    this->joint_1_length = joint_1_length;
    // Arm::joint_2_length = joint_2_length;
    // Arm::joint_1_range = joint_1_length;
    // Arm::joint_2_range = joint_2_range;
};

// bool Arm::activate(float joint_1_angle, float joint_2_angle)
// {
// }

// Point Arm::calculate_new_endpoint(float joint_1_angle, float joint_2_angle)
// {

// }

bool reachable(Point ref, vector<float> arm_joint_lengths, Point endpoint)
{
    float sum_arm_lengths = 0;
    for (auto &l : arm_joint_lengths)
    {
        sum_arm_lengths += l;
    }
    return sum_arm_lengths > distance(ref, endpoint);
}

vector<Point> remove_null_points(vector<Point> points)
{
    vector<Point> not_null_points;
    for (auto &p : points)
    {
        if (p != Point())
        {
            not_null_points.push_back(p);
        }
    }
    return not_null_points;
}

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

Point calculate_2dof_joint_angles(Point ref, Point endpoint, float joint_1_length, float joint_2_length)
{
    Point rel_endpoint = endpoint - ref;
    float x = rel_endpoint.x;
    float y = rel_endpoint.y;
    float joint_2_opp_angle = acos((sqr(x) + sqr(y) - sqr(joint_1_length) - sqr(joint_2_length)) / (2 * joint_1_length * joint_2_length));
    float joint_2_angle = PI - joint_2_opp_angle;
    float joint_1_angle = asin((joint_2_length * sin(joint_2_opp_angle)) / (sqr(x) + sqr(y))) + atan2(y, x);
    return Point{joint_1_angle, joint_2_angle};
}

float calculate_1dof_joint_angle(Point ref, Point endpoint, float joint_length)
{
    if (!reachable(ref, {joint_length}, endpoint))
        return 0.0;
    Point rel_endpoint = endpoint - ref;
    float x = rel_endpoint.x;
    float y = rel_endpoint.y;
    return atan2(y, x);
}

vector<float> calculate_multiple_1dof_joint_angles(Point ref, vector<Point> endpoints, float joint_length)
{
    vector<float> joint_angles;
    for (auto &p : endpoints)
    {
        if (reachable(ref, {joint_length}, p))
        {
            joint_angles.push_back(calculate_1dof_joint_angle(ref, p, joint_length));
        }
    }
    return joint_angles;
}

vector<Point> calculate_multiple_2dof_joint_angles(Point ref, vector<Point> endpoints, vector<float> joint_lengths)
{
    vector<Point> angles;
    for (int i = 0; i < endpoints.size(); i++)
    {
        if (reachable(ref, joint_lengths, endpoints.at(i)))
        {
            angles.push_back(calculate_2dof_joint_angles(ref, endpoints.at(i), joint_lengths.at(0), joint_lengths.at(1)));
        }
    }
    return angles;
}

vector<Point> interp_2dof_joint_angles(Point ref, vector<Point> endpoints, float joint_1_length, float joint_2_length, int num_points)
{
    vector<float> joint_2_interp_lengths;
    float step = joint_2_length / num_points;
    for (int i = 0; i < num_points; i++)
    {
        joint_2_interp_lengths.push_back(step * i);
    }
    vector<Point> interp_angles;
    for (int i = 0; i < joint_2_interp_lengths.size(); i++)
    {
        vector<Point> cur_angles = calculate_multiple_2dof_joint_angles(ref, endpoints, {joint_1_length, joint_2_interp_lengths.at(i)});
        interp_angles.insert(interp_angles.end(), cur_angles.begin(), cur_angles.end());
    }
    return remove_null_points(interp_angles);
}

vector<float> interp_1dof_joint_angles(Point ref, vector<Point> endpoints, float joint_length, int num_points)
{
    vector<float> joint_interp_lengths;
    float step = joint_length / num_points;
    for (int i = 0; i < num_points; i++)
    {
        joint_interp_lengths.push_back(step * i);
    }
    vector<float> interp_angles;
    for (int i = 0; i < joint_interp_lengths.size(); i++)
    {
        vector<float> cur_angles = calculate_multiple_1dof_joint_angles(ref, endpoints, joint_interp_lengths.at(i));
        interp_angles.insert(interp_angles.end(), cur_angles.begin(), cur_angles.end());
    }
    return interp_angles;
}