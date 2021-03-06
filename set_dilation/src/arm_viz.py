import matplotlib.pyplot as plt
import numpy as np


def plot(plt, coords, color, style, label=''):
    if not coords:
        return
    x_pts = []
    y_pts = []
    for i in range(0, len(coords) + 1):
        cur_x, cur_y, cur_z = coords[i % len(coords)]
        cur_x = float(cur_x)
        cur_y = float(cur_y)
        cur_z = float(cur_z)
        x_pts.append(cur_x)
        y_pts.append(cur_y)
    if len(coords) == 1:
        plt.scatter(x_pts, y_pts, s=[10])
        plt.annotate(label, (x_pts[0], y_pts[0]))
        return
    plt.plot(x_pts, y_pts, color=color, linestyle=style)


def read(f_name):
    coords = []
    f = open(f_name, 'r')
    for line in f:
        coords.append(line.split(','))
    return coords


def viz(dir_name):
    plt.axes()
    plt.title('Configuration space')
    plt.xlabel('Joint 1 angle (radians)')
    plt.ylabel('Joint 2 angle (radians)')
    coords_1 = read(dir_name + 'arm_results.txt')
    plot(plt, coords_1, 'r', 'solid')
    coords_2 = read(dir_name + 'angles_1.txt')
    plot(plt, coords_2, 'g', 'dashed', ' Start')
    coords_3 = read(dir_name + 'angles_2.txt')
    plot(plt, coords_3, 'b', 'dashed', ' Goal')
    # plt.axis('scaled')
    plt.xlim([0, np.pi])
    plt.ylim([0, np.pi])
    plt.show()


viz('/home/arjun/minkowski_addition/set_dilation/data/')
