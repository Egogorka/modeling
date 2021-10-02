//
// Created by meeve on 18.09.2021.
//

#include "state.h"

std::pair<float, float> kohan_sum(float sum, float comp, float sum_with) {
    float temp1 = sum_with - comp;
    float temp2 = sum + sum_with;
    float compens = (temp2 - sum) - temp1;
    return {temp2, compens};
}

State::State()
:State(0) {}

State::State(float omega)
:State(0.0f,0.0f,omega){}

State::State(float phi, float ksi, float omega)
:omega(omega), ksi(ksi), phi(phi){}

State::State(float phi, float ksi, float omega, float phi_comp, float ksi_comp)
:omega(omega), ksi(ksi), phi(phi), phi_comp(phi_comp), ksi_comp(ksi_comp){}

State &State::operator=(const State &other) = default;

State progress_basic(State &state, float dt) {
    auto phi = state.phi + state.ksi*dt;
    auto ksi = state.ksi - (state.omega)*(state.omega)*state.phi*dt;
    return {phi, ksi, state.omega};
}

State progress_alter(State &state, float dt) {
    auto phi_1 = state.phi + state.ksi*dt/2;
    auto ksi = state.ksi - (state.omega)*(state.omega)*phi_1*dt;
    auto phi = phi_1 + state.ksi*dt/2;
    return {phi, ksi, state.omega};
}

std::ostream &operator<<(std::ostream &out, State &state) {
    return out << state.phi << ' ' << state.ksi;
}

State progress_basic_comp(State &state, float dt) {
    auto phi_with_comp = kohan_sum(state.phi,state.phi_comp,state.ksi*dt);
    auto ksi_with_comp = kohan_sum(state.ksi,state.ksi_comp, -(state.omega)*(state.omega)*state.phi*dt);
    return {phi_with_comp.first, ksi_with_comp.first, state.omega, phi_with_comp.second, ksi_with_comp.second};
}

//State progress_alter_comp(State &state, float dt) {
//    auto phi_1 = state.phi + state.ksi*dt/2;
//    auto ksi = state.ksi - (state.omega)*(state.omega)*phi_1*dt;
//    auto phi = phi_1 + state.ksi*dt/2;
//    return {phi, ksi, state.omega};
//}