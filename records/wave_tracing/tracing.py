import matplotlib.pyplot as plt
import numpy as np

figure_size = (15,15)

def plot_data(t, phi, ksi):
    plt.subplot(1,1,1)
    # plt.axis([-3,12,-3,5])
    plt.plot(phi, ksi)

if __name__ == '__main__':
    plt.figure(figsize=figure_size)

    for N in range(20):
        t, rx, ry, kx, ky = np.loadtxt("data/euler/data"+str(N+1)+".csv", unpack=True)
        plot_data(t, rx, ry)
    plt.savefig("images/phase_diagram.png")
    plt.show()