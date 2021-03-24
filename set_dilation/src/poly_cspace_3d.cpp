#include "/home/arjun/minkowski_addition/set_dilation/include/utils.hpp"
/**
 * 
 **/

int main()
{
    vector<Point> results;
    vector<float> angles = interp_angles(0, PI, 6);
    cerr << angles.size();
    vector<vector<Point>> ego_poly;
    for (auto &angle : angles)
    {
        ego_poly.push_back(get_L(Point(), 0.75, true, true, 2, angle));
    }
    vector<Point> obs = get_obstacle(Point(10, 10), 4, false, true, 32);
    results = compute_cspace_3d(ego_poly, obs, angles);
    write_shape_to_file("poly_results_3d.txt", results);
    return 1;
}