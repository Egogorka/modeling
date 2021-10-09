//
// Created by meeve on 18.09.2021.
//

#ifndef MODELING_STATE__H
#define MODELING_STATE__H

#include <iostream>
#include "KahanFloat.h"

class State {
    KahanFloat phi;
    KahanFloat ksi;

    float omega;
public:
    State();
    explicit State(float omega);
    State(float phi, float ksi, float omega);
    State& operator= (const State& other);

    void progress_basic(float dt);
    void progress_alter(float dt);
//    void progress_basic_comp(float dt);

    friend std::ostream& operator<<(std::ostream& out, State& state);
};

#endif //MODELING_STATE__H
