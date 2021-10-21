//
// Created by meeve on 16.10.2021.
//

#ifndef MODELING_ODE_H
#define MODELING_ODE_H

#include "typedefs.h"

namespace modeling {

    template<typename V>
    V identity(const V& vec){
        return vec;
    }

    template<typename V, typename scalar>
    class ODE_Solver {
    private:
        // function_ that corresponds to y' = F(t,y)
        Operator<V> function_;
    public:
        V state;
        V start_state;

        ODE_Solver(V state, Operator<V> func) : state(state), start_state(state), function_(func) {};
        ODE_Solver(V state): ODE_Solver(state, identity<V>) {};

        void reset_state(){
            state = start_state;
        }

        void euler(scalar dt) {
            state += function_(state) * dt;
        }

        void heun(scalar dt) {
            // forecast
            auto forecast = state + function_(state) * dt;
            // better the forecast
            state += (function_(state) + function_(forecast)) / scalar(2) * dt;
        }
    };

}

#endif //MODELING_ODE_H
