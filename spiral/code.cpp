//
// Created by meeve on 25.09.2021.
//

#include <iostream>
#include "state.h"
#include <fstream>

int sem_1_1 () {
    std::ofstream fout2, fout3;

    const int N = 4;
    int n = 1;

    // cycle for dt
    for(unsigned j=0; j<N; ++j){
        std::string temp2("../data/alter/data"); temp2 += std::to_string(j+1); temp2 += ".csv";
        std::string temp3("../data/basic_comp/data"); temp3 += std::to_string(j+1); temp3 += ".csv";

        fout2.open(temp2);
        fout3.open(temp3);

        State start_state(10.0f, 0.0f, 2.0f);
        float t = 1.0f; n *= 10;

        State state(start_state);
        for(unsigned i=0; i<n; i++){
            if( i % 10 == 0)
                fout3 << t/float(n)*float(i) << ' ' << state << '\n';
            state.progress_basic(t/float(n));
        }

//        state = start_state;
//        for(unsigned i=0; i<n; i++){
//            if( i % 10 == 0)
//                fout2 << t/float(n)*float(i) << ' ' << state << '\n';
//            state.progress_alter(t/float(n));
//        }

        fout2.close();
        fout3.close();
    }
    return 0;
}