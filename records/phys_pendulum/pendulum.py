import matplotlib.pyplot as plt
import numpy as np

figure_size = (30,15)

def plot_data(t, phi, ksi):
    plt.subplot(1,1,1)
    plt.axis([-12,12,-12,12])
    plt.plot(phi, ksi)

if __name__ == '__main__':
    plt.figure(figsize=figure_size)

    for N in range(20):
        t, phi, ksi = np.loadtxt("data/heun/data"+str(N+1)+".csv", unpack=True)
        plot_data(t, phi, ksi)
    plt.show()