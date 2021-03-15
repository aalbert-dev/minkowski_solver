#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"

int main()
{
    vector<Point> results;
    vector<float> angles = interp_angles(0, PI, 2);
    vector<Point> obs_2 = get_obstacle(Point(10, 10), 4, false, true, 64);
    for (auto &angle : angles)
    {
        vector<Point> L_1 = get_L(Point(), 0.75, true, true, 8, angle);
        vector<Point> result = compute_cspace_2d(L_1, obs_2);
        for (int i = 0; i < result.size(); i++)
        {
            result.at(i).z = angle;
        }
        results.insert(results.end(), result.begin(), result.end());
    }
    write_shape_to_file("poly_results_3d.txt", results);
    return 1;
}