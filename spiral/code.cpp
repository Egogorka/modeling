//
// Created by meeve on 25.09.2021.
//

#include <iostream>
#include "state.h"
#include <fstream>

int sem_1() {
    std::ofstream fout;
    fout.open("./data1.csv");

    State start_state(10.0f, 0.0f, 2.0f);
    float t = 10.0f; int n = 100000;

    State state(start_state);
    for(unsigned i=0; i<n; i++){
        fout << t/float(n)*float(i) << ' ' << state << '\n';
        state = progress_basic(state, t/float(n));
    }

    fout.close();
    fout.open("./data2.csv");

    state = start_state;
    for(unsigned i=0; i<n; i++){
        fout << t/float(n)*float(i) << ' ' << state << '\n';
        state = progress_alter(state, t/float(n));
    }

    fout.close();
    return 0;
}

int sem_1_1 () {
    std::ofstream fout1, fout2, fout3;

    const int N = 5;
    int n = 1;

    // cycle for dt
    for(unsigned j=0; j<N; ++j){
        std::string temp1("./data/basic/data"); temp1 += std::to_string(j); temp1 += ".csv";
        std::string temp2("./data/alter/data"); temp2 += std::to_string(j); temp2 += ".csv";
        std::string temp3("./data/basic_comp/data"); temp3 += std::to_string(j); temp3 += ".csv";

        fout1.open(temp1);
        fout2.open(temp2);
        fout3.open(temp3);

        State start_state(10.0f, 0.0f, 2.0f);
        float t = 10.0f; n *= 10;

        State state(start_state);
        for(unsigned i=0; i<n; i++){
            fout1 << t/float(n)*float(i) << ' ' << state << '\n';
            state = progress_basic(state, t/float(n));
        }

        state = start_state;
        for(unsigned i=0; i<n; i++){
            fout2 << t/float(n)*float(i) << ' ' << state << '\n';
            state = progress_alter(state, t/float(n));
        }

        state = start_state;
        for(unsigned i=0; i<n; i++){
            fout3 << t/float(n)*float(i) << ' ' << state << '\n';
            state = progress_basic_comp(state, t/float(n));
        }

        fout1.close();
        fout2.close();
        fout3.close();
    }
    return 0;
}