//
// Created by meeve on 13.11.2021.
//

#ifndef MODELING_WAVETRACING_H
#define MODELING_WAVETRACING_H
#include <functional>
#include "ODE.h"
#include "Vector.h"
#include "typedefs.h"

#include "cmath"

namespace modeling {

    using namespace std::placeholders;
    template<typename T>
    using Vector4 = Vector<T,4>;

    // Kahan float or just float
    template<typename T>
    class WaveTracing: public ODE_Solver<Vector4<T>,float> {
    private:
        typedef std::function<T(Vector2<T>)> scalar_func;
        typedef std::function<Vector2<T>(Vector2<T>)> vector_func;

        scalar_func n_e;
        vector_func grad_n_e;

        Vector4<T> func(const Vector4<T>& vec, float omega){
            Vector2<T> r{vec[0], vec[1]};
            Vector2<T> k{vec[2], vec[3]};

            return {
                -3/n_e(r)*k[0]/omega/2,
                -3/n_e(r)*k[1]/omega/2,
                (-grad_n_e(r)[0] + 3*grad_n_e(r)[0]/n_e(r)/n_e(r))/omega/2,
                (-grad_n_e(r)[1] + 3*grad_n_e(r)[1]/n_e(r)/n_e(r))/omega/2,
            };
        }
    public:
        WaveTracing(float omega,
                    scalar_func n_e, vector_func grad_n_e,
                    const Vector4<T>& vec):
        ODE_Solver<Vector4<T>, float>{
            vec, [this, omega](const Vector4<T>& vector){
                return this->func(vector, omega);
            }
        },
        n_e(n_e), grad_n_e(grad_n_e) {};
    };

}

#endif //MODELING_WAVETRACING_H
