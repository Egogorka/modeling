//
// Created by meeve on 16.10.2021.
//

#ifndef MODELING_ODE_H
#define MODELING_ODE_H

template<typename vec, typename scalar>
class ODE_Solver {
private:
    typedef vec (*matrix)(const vec&);
    matrix func;
public:
    vec state;

    ODE_Solver(vec state, matrix func): state(state), func(func) {};

    void euler(scalar dt){
        state += func(state) * dt;
    }

    void heun(scalar dt){
        // forecast
        auto forecast = state + func(state) * dt;
        // better the forecast
        state += (func(state) + func(forecast)) / scalar(2) * dt;
    }
};


#endif //MODELING_ODE_H
