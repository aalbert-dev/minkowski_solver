import matplotlib.pyplot as plt


def plot(plt, coords, color, style):
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
    plt.xlabel('X meters')
    plt.ylabel('Y meters')
    coords_1 = read(dir_name + 'poly_results.txt')
    plot(plt, coords_1, 'r', 'solid')
    coords_2 = read(dir_name + 'shape_1.txt')
    plot(plt, coords_2, 'g', 'dashed')
    coords_3 = read(dir_name + 'shape_2.txt')
    plot(plt, coords_3, 'b', 'dashed')
    plt.axis('scaled')
    plt.show()


viz('/home/arjun/minkowski_addition/set_dilation/data/')
