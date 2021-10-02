//
// Created by meeve on 25.09.2021.
//

#ifndef MODELING_KAHANFLOAT_H
#define MODELING_KAHANFLOAT_H

struct KahanFloat {
    float value;
    float compensation;

    KahanFloat();
    explicit KahanFloat(float value);
    KahanFloat(float value, float compensation);

    KahanFloat& operator=(const KahanFloat& other);
};

//KahanFloat operator+(const KahanFloat& a, const KahanFloat& b);
KahanFloat operator+(const KahanFloat& a, float b);

//KahanFloat operator-(const KahanFloat& a, const KahanFloat& b);



#endif //MODELING_KAHANFLOAT_H
