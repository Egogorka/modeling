import matplotlib.pyplot as plt
import numpy as np

# In the case of math pendulum we just compare the phase diagrams of different techniques and corresponding energy graphs
# So we need the basic print plotter
# Because we have only 4 techniques (heun and euler * kahan and not) we would need 2 rows and 4 columns
figure_size = (30,15)
# I did not export omega value directly, so we need to make a variable for that
omega = 1.0
# And that is also true for start energy
H_0 = 10*10 / 2

# There we expect t, phi, ksi as a tuple of 4 different inputs from techniques
def plot_data(t, phi, ksi):
    phase_text = (
        "euler",
        "euler_kah",
        "heun",
        "heun_kah"
    )

    for i in range(4):
        H = (np.multiply(ksi[i], ksi[i]))/2 + omega*omega*np.multiply(phi[i], phi[i])/2
        H = np.log10(H/H_0-1)

        plt.subplot(2,4,i+1)
        plt.axis([-12,12,-12,12])
        plt.plot(phi[i], ksi[i])
        plt.title(phase_text[i])

        plt.subplot(2,4,i+5)
        plt.plot(t[i], H)
        plt.title("Energy, log(H/H_0 - 1)")


if __name__ == '__main__':
    plt.figure(figsize=figure_size)

    for N in range(1,9):
        print("making images for N =", N)
        t1, phi1, ksi1 = np.loadtxt("data/euler/data"+str(N)+".csv", unpack=True)
        t2, phi2, ksi2 = np.loadtxt("data/euler_kah/data"+str(N)+".csv", unpack=True)
        t3, phi3, ksi3 = np.loadtxt("data/heun/data"+str(N)+".csv", unpack=True)
        t4, phi4, ksi4 = np.loadtxt("data/heun_kah/data"+str(N)+".csv", unpack=True)

        plot_data((t1, t2, t3, t4), (phi1, phi2, phi3, phi4), (ksi1, ksi2, ksi3, ksi4))
        plt.savefig("images/order"+str(N)+".png")
        plt.clf()
    plt.show()


