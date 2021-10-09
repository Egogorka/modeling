//
// Created by meeve on 18.09.2021.
//

#include "state_.h"

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

State &State::operator=(const State &other) = default;

//void State::progress_basic(float dt) {
//    auto phi_ = phi + ksi*dt;
//    auto ksi_ = ksi - omega*omega*phi*dt;
//
//}

void State::progress_alter(float dt) {
    auto phi_1 = phi + ksi*dt*0.5;
    auto ksi_2 = ksi - omega*omega*phi_1*dt;
    auto phi_2 = phi_1 + ksi*dt*0.5;
    phi = phi_2;
    ksi = ksi_2;
}

void State::progress_basic(float dt) {
    auto phi_ = phi + ksi*dt;
    auto ksi_ = ksi - omega*omega*phi*dt;
    phi = phi_;
    ksi = ksi_;
}

std::ostream &operator<<(std::ostream &out, State &state) {
    return out << state.phi.value << ' ' << state.ksi.value;
}


//State progress_alter_comp(State &state, float dt) {
//    auto phi_1 = state.phi + state.ksi*dt/2;
//    auto ksi = state.ksi - (state.omega)*(state.omega)*phi_1*dt;
//    auto phi = phi_1 + state.ksi*dt/2;
//    return {phi, ksi, state.omega};
//}