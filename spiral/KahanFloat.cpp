//
// Created by meeve on 02.10.2021.
//

#include "KahanFloat.h"

KahanFloat::KahanFloat():
value(), compensation() {}

KahanFloat::KahanFloat(float value):
value(value), compensation() {}

KahanFloat::KahanFloat(float value, float compensation):
value(value), compensation(compensation) {}

KahanFloat &KahanFloat::operator=(const KahanFloat &other) = default;

KahanFloat operator+(const KahanFloat& a, float b) {
    auto temp1 = b - a.compensation;
    auto out = a.value + b;
    auto comp = (out - a.value) - temp1;
    return {out, comp};
}

//KahanFloat operator+(const KahanFloat& a, const KahanFloat& b) {
//    auto comp = a.compensation + b.compensation;
//
//
//}
//KahanFloat operator-(const KahanFloat& a, const KahanFloat& b);

