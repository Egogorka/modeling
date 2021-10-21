#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
//
// Created by meeve on 25.09.2021.
//

#ifndef MODELING_KAHANFLOAT_H
#define MODELING_KAHANFLOAT_H

#include <iostream>

struct KahanFloat {
    float value;
    float compensation;

    KahanFloat();
    KahanFloat(float value);
    KahanFloat(float value, float compensation);

    [[nodiscard]] float collapse() const;

    KahanFloat& operator=(const KahanFloat& other);
    KahanFloat& operator+=(float other);
    KahanFloat& operator*=(float other);
    KahanFloat& operator-=(float other);

    KahanFloat& operator+=(const KahanFloat& other);
    KahanFloat& operator-=(const KahanFloat& other);

    KahanFloat operator-() const;
};

KahanFloat operator+(const KahanFloat& a, float b);
KahanFloat operator+(float b, const KahanFloat& a);
KahanFloat operator*(const KahanFloat& a, float b);
KahanFloat operator*(float b, const KahanFloat& a);
KahanFloat operator/(const KahanFloat& a, float b);

KahanFloat operator-(const KahanFloat& a, float b);
KahanFloat operator-(float b, const KahanFloat& a);

KahanFloat operator+(const KahanFloat& a, const KahanFloat& b);
KahanFloat operator-(const KahanFloat& a, const KahanFloat& b);

std::ostream& operator<<(std::ostream& os, const KahanFloat& a);

#endif //MODELING_KAHANFLOAT_H

#pragma clang diagnostic pop