//
// Created by Meevere on 21.10.2021.
//

#ifndef MODELING_MATHPENDULUM_H
#define MODELING_MATHPENDULUM_H

#include <functional>
#include "ODE.h"

namespace modeling {

    using namespace std::placeholders;

    // Kahan float or just float
    template<typename T>
    class MathPendulum: public ODE_Solver<Vector2<T>,float> {
    private:
        static Vector2<T> func(const Vector2<T>& vec, float omega){
            return {vec[1],-omega*omega*vec[2]};
        }
    public:
        MathPendulum(float omega, const Vector2<T>& vec):
            ODE_Solver<Vector2<T>,float>(
                vec,
                std::bind(func, _1, omega)
            ){};
        MathPendulum(float omega, T phi, T ksi):
            MathPendulum(omega, Vector2<T>{phi, ksi}){};
        MathPendulum(float omega):
            MathPendulum(omega, T(), T()){};
    };

}
#endif //MODELING_MATHPENDULUM_H
