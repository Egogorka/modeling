//
// Created by meeve on 16.10.2021.
//

#ifndef MODELING_ARRAY_H
#define MODELING_ARRAY_H

#include <array>
#include <iostream>

template<typename T, std::size_t n>
std::array<T,n>& operator+=(std::array<T,n>& a,const std::array<T,n>& b) {
    for(unsigned i=0; i<n; ++i) {
        a[i] += b[i];
    }
    return a;
}

template<typename T, std::size_t n>
std::array<T,n> operator+(const std::array<T,n>& a,const std::array<T,n>& b) {
    std::array<T,n> out(a);
    out += b;
    return out;
}

template<typename T, std::size_t n>
std::array<T,n> operator-(const std::array<T,n>& a,const std::array<T,n>& b) {
    std::array<T,n> out;
    for(unsigned i=0; i<n; ++i) {
        out[i] = a[i] - b[i];
    }
    return out;
}

template<typename T, std::size_t n>
std::array<T,n> operator*(const std::array<T,n>& a,T b) {
    std::array<T,n> out;
    for(unsigned i=0; i<n; ++i) {
        out[i] = a[i] * b;
    }
    return out;
}

template<typename T, std::size_t n>
std::array<T,n> operator*(T b, const std::array<T,n>& a) {return a*b;}

template<typename T, std::size_t n>
std::array<T,n> operator/(const std::array<T,n>& a, T b) {return a*(T(1)/b);}

template<typename T, std::size_t n>
std::ostream& operator<<(std::ostream& out, std::array<T,n> arr){
    for( auto elem : arr ){
        out << elem << ' ';
    }
    return out;
}


#endif //MODELING_ARRAY_H
