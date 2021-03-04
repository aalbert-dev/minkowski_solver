import matplotlib.pyplot as plt

def plot():
    plt.axes()
    plt.axis('scaled')
    plt.show()

def read(f_name):
    f = open(f_name, 'r')
    for line in f:
        x, y, z = line.split(',')
        print(x, y, z)

read('results.txt')
