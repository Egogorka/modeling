import matplotlib.pyplot as plt
import numpy as np

N = 8

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # t, phi, ksi = np.loadtxt("../data/basic/data"+str(N)+".csv", unpack=True)
    # H = (np.multiply(ksi, ksi) + 4*np.multiply(phi, phi))/400 - 1

    plt.figure(figsize=(6, 9))

    # plt.subplot(3, 2, 1)  # 3-строки, 1 столбец, 1 индекс
    # plt.plot(ksi, phi)

    # print("Energy1(t)")

    # plt.subplot(3, 2, 2)  # 3-строки, 1 столбец, 1 индекс
    # plt.title("Energy1(t)")
    # plt.plot(t, H)

    t, phi, ksi = np.loadtxt("../data/alter/data"+str(N)+".csv", unpack=True)
    H = (np.multiply(ksi, ksi) + 4 * np.multiply(phi, phi))/400 - 1

    plt.subplot(3, 2, 3)  # 3-строки, 1 столбец, 1 индекс
    plt.plot(ksi, phi)

    print("Energy2(t)")

    plt.subplot(3, 2, 4)  # 3-строки, 1 столбец, 1 индекс
    plt.title("(H(t)-E)/E, N=8, alter")
    plt.plot(t, H)

    t, phi, ksi = np.loadtxt("../data/basic_comp/data"+str(N)+".csv", unpack=True)
    H = (np.multiply(ksi, ksi) + 4 * np.multiply(phi, phi))/400 - 1

    plt.subplot(3, 2, 5)  # 3-строки, 1 столбец, 1 индекс
    plt.plot(ksi, phi)

    print("Energy3(t)")

    plt.subplot(3, 2, 6)  # 3-строки, 1 столбец, 1 индекс
    plt.title("(H(t)-E)/E, N=8, basic")
    plt.plot(t, H)


    plt.show()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
