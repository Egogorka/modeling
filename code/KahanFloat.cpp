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

KahanFloat& KahanFloat::operator=(const KahanFloat &other) = default;

//////////////////////////////////////////////////////////////////////

KahanFloat KahanFloat::operator-() const {
    KahanFloat out(-value, -compensation);
    return out;
}

float KahanFloat::collapse() const   {
    return value + compensation;
}

//////////////////////////////////////////////////////////////////////
// Between KahanFloats and floats
//////////////////////////////////////////////////////////////////////

KahanFloat& KahanFloat::operator+=(float other){
    auto temp1 = other - compensation;
    auto out = value + temp1;
    auto comp = (out - value) - temp1;
    value = out; compensation = comp;
    return *this;
}

KahanFloat& KahanFloat::operator-=(float other){ return (*this)+= -other; }

KahanFloat& KahanFloat::operator*=(float other){
    value *= other;
    compensation *= other;
    return *this;
}

KahanFloat operator+(const KahanFloat& a, float b) {
    KahanFloat out(a.value, a.compensation);
    out += b;
    return out;
}

KahanFloat operator*(const KahanFloat& a, float b){
    KahanFloat out(a.value, a.compensation);
    out *= b;
    return out;
}

KahanFloat operator/(const KahanFloat& a, float b){ return a * (1/b); }
KahanFloat operator-(const KahanFloat& a, float b){ return a + (-b); }
KahanFloat operator+(float b, const KahanFloat& a){ return a + b; }
KahanFloat operator*(float b, const KahanFloat& a){ return a * b; }
KahanFloat operator-(float b, const KahanFloat& a){ return a + (-b); }

//////////////////////////////////////////////////////////////////////
// Between KahanFloats
//////////////////////////////////////////////////////////////////////

KahanFloat &KahanFloat::operator+=(const KahanFloat &other) {
    auto temp1 = other.value - compensation - other.compensation;
    auto out = value + temp1;
    auto comp = (out - value) - temp1;
    value = out; compensation = comp;
    return *this;
}

KahanFloat &KahanFloat::operator-=(const KahanFloat &other) {
    *this += -other;
    return *this;
}

KahanFloat operator+(const KahanFloat& a, const KahanFloat& b){
    KahanFloat out(a.value, a.compensation);
    out += b;
    return out;
}
KahanFloat operator-(const KahanFloat& a, const KahanFloat& b){
    KahanFloat out(a.value, a.compensation);
    out += -b;
    return out;
}

std::ostream& operator<<(std::ostream& os, const KahanFloat& a){
    return os << a.value;
}