//
// Created by Meevere on 21.10.2021.
//

#ifndef MODELING_PHYSPENDULUM_H
#define MODELING_PHYSPENDULUM_H

#include <functional>
#include "ODE.h"

#include "cmath"

namespace modeling {

    using namespace std::placeholders;

    // Kahan float or just float
    template<typename T>
    class PhysPendulum: public ODE_Solver<Vector2<T>,float> {
    private:
        static Vector2<T> func(const Vector2<T>& vec, float omega){
            return {vec[1],
                    -omega*omega*float(sin(vec[0]))};
        }
    public:
        PhysPendulum(float omega, const Vector2<T>& vec):
                ODE_Solver<Vector2<T>,float>(
                        vec,
                        std::bind(func, _1, omega)
                ){};
        PhysPendulum(float omega, T phi, T ksi):
                PhysPendulum(omega, Vector2<T>{phi, ksi}){};
        PhysPendulum(float omega):
                PhysPendulum(omega, T(), T()){};
    };

}

#endif //MODELING_PHYSPENDULUM_H
