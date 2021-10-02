//
// Created by meeve on 18.09.2021.
//

#ifndef MODELING_STATE_H
#define MODELING_STATE_H

#include <iostream>

class State {
    float phi; float phi_comp = 0.0f;
    float ksi; float ksi_comp = 0.0f;

    float omega;
public:
    State();
    State(float omega);
    State(float phi, float ksi, float omega);
    State(float phi, float ksi, float omega, float phi_comp, float ksi_comp);
    State& operator= (const State& other);

    friend State progress_basic(State& state, float dt);
    friend State progress_alter(State& state, float dt);
    friend State progress_basic_comp(State& state, float dt);
//    friend State progress_alter_comp(State& state, float dt);

    friend std::ostream& operator<<(std::ostream& out, State& state);
};

State progress_basic(State& state, float dt);
State progress_alter(State& state, float dt);

State progress_basic_comp(State& state, float dt);
//State progress_alter_comp(State& state, float dt);



#endif //MODELING_STATE_H
