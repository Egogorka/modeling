//
// Created by meeve on 16.10.2021.
//

#ifndef MODELING_STATENEW_H
#define MODELING_STATENEW_H

#endif //MODELING_STATENEW_H

template<typename T>
StateNew default_updater(const StateNew& state) {
    return StateNew(state);
}

template<typename T>
class StateNew {
protected:
    typedef StateNew(*updater_func)(const StateNew&)

    T phi = T();
    T ksi = T();

    updater_func updater = default_updater;
public:
    StateNew(const T& phi, const T& ksi): phi(phi), ksi(ksi){}
    StateNew(const T& phi, const T& ksi, updater_func updater): phi(phi), ksi(ksi), updater(updater){}

    StateNew(const StateNew& state) = default;
    StateNew& operator=(const StateNew& state) = default;

    void update() { *this = updater(*this); }
};
