//
// Created by meeve on 16.10.2021.
//

#ifndef MODELING_VECTOR_H
#define MODELING_VECTOR_H

#include <array>
#include <iostream>

namespace modeling {

    template<typename T, std::size_t N>
    using Vector = std::array<T,N>;

    template<typename T>
    using Vector2 = Vector<T, 2>;

    // Vector +=(Vector& a, Vector &b)

    template<typename T, std::size_t n>
    Vector<T, n> &operator+=(Vector<T, n> &a, const Vector<T, n> &b) {
        for (unsigned i = 0; i < n; ++i) {
            a[i] += b[i];
        }
        return a;
    }

    template<typename T, std::size_t n>
    Vector<T, n> operator+(const Vector<T, n> &a, const Vector<T, n> &b) {
        Vector<T, n> out(a);
        out += b;
        return out;
    }

    template<typename T, std::size_t n>
    Vector<T, n> operator-(const Vector<T, n> &a, const Vector<T, n> &b) {
        Vector<T, n> out;
        for (unsigned i = 0; i < n; ++i) {
            out[i] = a[i] - b[i];
        }
        return out;
    }

    template<typename T, std::size_t n>
    Vector<T, n> operator*(const Vector<T, n> &a, T b) {
        Vector<T, n> out;
        for (unsigned i = 0; i < n; ++i) {
            out[i] = a[i] * b;
        }
        return out;
    }

    template<typename T, std::size_t n>
    Vector<T, n> operator*(T b, const Vector<T, n> &a) { return a * b; }

    template<typename T, std::size_t n>
    Vector<T, n> operator/(const Vector<T, n> &a, T b) { return a * (T(1) / b); }

    template<typename T, std::size_t n>
    std::ostream &operator<<(std::ostream &out, Vector<T, n> arr) {
        for (auto elem : arr) {
            out << elem << ' ';
        }
        return out;
    }

}

#endif //MODELING_VECTOR_H
