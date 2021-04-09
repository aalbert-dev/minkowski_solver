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


def get_colors_from_angles(z_coords):
    num_points = len(z_coords)
    unique_z = []

    for z in z_coords:
        if z not in unique_z:
            unique_z.append(z)
    z_length = num_points // len(unique_z)
    color_seq = []
    for i in range(0, num_points):
        col_index = int(i / z_length)
        color_seq.append(col_index)
    return color_seq


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
        x_pts.append(float(cur_x))
        y_pts.append(float(cur_y))
        z_pts.append(float(cur_z))
    color_seq = get_colors_from_angles(z_pts)
    ax.scatter(x_pts, y_pts, z_pts, s=50, c=color_seq)
    ax.set_xlabel('X Meters')
    ax.set_ylabel('Y Meters')
    ax.set_zlabel('Z Radians')
    plt.title('Configuration space')
    plt.show()


viz('/home/arjun/minkowski_addition/set_dilation/data/')
