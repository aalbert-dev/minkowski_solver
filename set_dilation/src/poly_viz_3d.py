import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import random


def plot(plt, coords, color, style):
    if not coords:
        return
    x_pts = []
    y_pts = []
    z_pts = []
    for i in range(0, len(coords) + 1):
        cur_x, cur_y, cur_z = coords[i % len(coords)]
        cur_x = float(cur_x)
        cur_y = float(cur_y)
        cur_z = float(cur_z)
        x_pts.append(cur_x)
        y_pts.append(cur_y)
        z_pts.append(cur_z)
    plt.plot(x_pts, y_pts, color=color, linestyle=style)


def read(f_name):
    coords = []
    f = open(f_name, 'r')
    for line in f:
        coords.append(line.split(','))
    return coords


def get_cmap(n, name='hsv'):
    return plt.cm.get_cmap(name, n)


def viz(dir_name):
    fig = plt.figure()

    ax = Axes3D(fig)
    coords = read(dir_name + 'poly_results_3d.txt')
    if not coords:
        return
    x_pts = []
    y_pts = []
    z_pts = []
    for i in range(0, len(coords) + 1):
        cur_x, cur_y, cur_z = coords[i % len(coords)]
        cur_x = float(cur_x)
        cur_y = float(cur_y)
        cur_z = float(cur_z)
        x_pts.append(cur_x)
        y_pts.append(cur_y)
        z_pts.append(cur_z)
    sequence_containing_x_vals = x_pts
    sequence_containing_y_vals = y_pts
    sequence_containing_z_vals = z_pts
    # num_angles = 4
    # num_points = len(z_pts)
    color_seq = [0 if i > 84241/2 else 1 for i in range(0, 84241)]
    ax.scatter(sequence_containing_x_vals,
               sequence_containing_y_vals, sequence_containing_z_vals, s=5, c=color_seq)

    plt.show()


viz('/home/arjun/minkowski_addition/set_dilation/data/')
