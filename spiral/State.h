//
// Created by meeve on 09.10.2021.
//

#ifndef MODELING_STATE_H
#define MODELING_STATE_H

#include <iostream>

template<typename T, typename N=T>
class State {
protected:
    T phi;
    T ksi;

    N omega;
public:
    State():phi(), ksi(), omega() {}
    explicit State(N omega):phi(), ksi() {}
    State(T phi, T ksi, N omega):phi(phi), ksi(ksi), omega(omega) {}

    void progress_basic(N dt) {
        auto phi_ = phi + ksi*dt;
        auto ksi_ = ksi - omega*omega*phi*dt;
        phi = phi_;
        ksi = ksi_;
    }

    void progress_alter(N dt) {
        auto phi_1 = phi + ksi*dt*0.5;
        auto ksi_2 = ksi - omega*omega*phi_1*dt;
        auto phi_2 = phi_1 + ksi*dt*0.5;
        phi = phi_2;
        ksi = ksi_2;
    }

    void progress_heun(N dt) {
        // first - we forecast
        auto phi_forecast = phi + ksi*dt;
        auto ksi_forecast = ksi - omega*omega*phi*dt;

        // then we better the solution
        phi = phi + dt * (ksi + ksi_forecast) / 2;
        ksi = ksi - dt * (phi + phi_forecast) * omega * omega / 2;
    }


    friend std::ostream& operator<<(std::ostream& out, State& state){
        return out << state.phi << ' ' << state.ksi;
    }
};



#endif //MODELING_STATE_H
