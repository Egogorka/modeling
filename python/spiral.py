import matplotlib.pyplot as plt
import numpy as np

N = 6

def qwerty(t, phi, ksi, H, n):
    plt.subplot(3, 2, n)  # 3-строки, 1 столбец, 1 индекс
    plt.plot(ksi, phi)
    plt.subplot(3, 2, n+1)  # 3-строки, 1 столбец, 1 индекс
    plt.plot(t, H)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    plt.figure(figsize=(6, 9))

    t, phi, ksi = np.loadtxt("../data/basic/data"+str(N)+".csv", unpack=True)
    H = (np.multiply(ksi, ksi) + 4*np.multiply(phi, phi))/400 - 1
    qwerty(t, phi, ksi, H, 1)

    t, phi, ksi = np.loadtxt("../data/alter/data"+str(N)+".csv", unpack=True)
    H = (np.multiply(ksi, ksi) + 4 * np.multiply(phi, phi))/400 - 1
    qwerty(t, phi, ksi, H, 3)

    t, phi, ksi = np.loadtxt("../data/heun/data"+str(N)+".csv", unpack=True)
    H = (np.multiply(ksi, ksi) + 4 * np.multiply(phi, phi))/400 - 1
    qwerty(t, phi, ksi, H, 5)

    # t, phi, ksi = np.loadtxt("../data/alter_kah/data"+str(N)+".csv", unpack=True)
    # H = (np.multiply(ksi, ksi) + 4 * np.multiply(phi, phi))/400 - 1
    # qwerty(t, phi, ksi, H, 7)

    plt.show()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
