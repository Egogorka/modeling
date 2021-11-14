import math

import matplotlib.pyplot as plt
import numpy as np

figure_size = (15,15)

def plot_data(t, phi, ksi):
    plt.subplot(1,1,1)
    plt.axis([-3,12,-3,5])
    plt.plot(phi, ksi)


omega = 1


def plot_energy(t, phi, ksi):
    plt.subplot(1,1,1)
    h = ksi*ksi + omega*omega*(1-np.cos(phi))
    plt.plot(t, np.log(h))


if __name__ == '__main__':
    plt.figure(figsize=figure_size)

    for N in range(20):
        t, phi, ksi = np.loadtxt("data/euler/data"+str(N+1)+".csv", unpack=True)
        plot_data(t, phi, ksi)
    plt.savefig("images/phase_diagram_euler.png")
    plt.clf()

    for N in range(20):
        t, phi, ksi = np.loadtxt("data/euler/data"+str(N+1)+".csv", unpack=True)
        plot_energy(t, phi, ksi)
    plt.savefig("images/energy_euler.png")
    plt.clf()

    for N in range(20):
        t, phi, ksi = np.loadtxt("data/heun/data"+str(N+1)+".csv", unpack=True)
        plot_data(t, phi, ksi)
    plt.savefig("images/phase_diagram_heun.png")
    plt.show()
    plt.clf()

    for N in range(20):
        t, phi, ksi = np.loadtxt("data/heun/data"+str(N+1)+".csv", unpack=True)
        plot_energy(t, phi, ksi)
    plt.savefig("images/energy_heun.png")
    plt.clf()

