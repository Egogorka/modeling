import matplotlib.pyplot as plt
import numpy as np

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    t, phi, ksi = np.loadtxt("data1.csv", unpack=True)
    H = np.multiply(ksi, ksi) + 4*np.multiply(phi, phi)

    plt.figure(figsize=(6, 9))

    plt.subplot(2, 2, 1)  # 3-строки, 1 столбец, 1 индекс
    plt.plot(ksi, phi)

    plt.subplot(2, 2, 2)  # 3-строки, 1 столбец, 1 индекс
    plt.title("Energy1(t)")
    plt.plot(t, H)

    t, phi, ksi = np.loadtxt("data2.csv", unpack=True)
    H = np.multiply(ksi, ksi) + 4 * np.multiply(phi, phi)

    plt.subplot(2, 2, 3)  # 3-строки, 1 столбец, 1 индекс
    plt.plot(ksi, phi)

    plt.subplot(2, 2, 4)  # 3-строки, 1 столбец, 1 индекс
    plt.title("Energy2(t)")
    plt.plot(t, H)


    plt.show()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
