//
// Created by meeve on 13.11.2021.
//

#ifndef MODELING_PHYSPENDULUMFRICTION_H
#define MODELING_PHYSPENDULUMFRICTION_H

#include <functional>
#include "ODE.h"

#include "cmath"

namespace modeling {

    using namespace std::placeholders;

    // Kahan float or just float
    template<typename T>
    class PhysPendulumFriction: public ODE_Solver<Vector2<T>,float> {
    private:
        static Vector2<T> func(const Vector2<T>& vec, float omega, float k){
            return {vec[1],
                    -omega*omega*float(sin(float(vec[0])))-k*vec[1]};
        }
    public:
        PhysPendulumFriction(float omega, float k, const Vector2<T>& vec):
        ODE_Solver<Vector2<T>,float>(
                vec,
                std::bind(func, _1, omega, k)
                ){};
        PhysPendulumFriction(float omega, float k, T phi, T ksi):
            PhysPendulumFriction(omega, k, Vector2<T>{phi, ksi}){};
        PhysPendulumFriction(float omega, float k):
        PhysPendulumFriction(omega, k, T(), T()){};
    };

}

#endif //MODELING_PHYSPENDULUMFRICTION_H
