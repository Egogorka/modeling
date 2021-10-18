//
// Created by meeve on 25.09.2021.
//

#include <iostream>
#include "State.h"
#include "KahanFloat.h"
#include <fstream>

int sem_1_1 () {
    std::ofstream fout0, fout1, fout2, fout3;

    const int N = 8;
    int n = 1;

    // cycle for dt
    for(unsigned j=0; j<N; ++j){
        std::cout << "---------j=" << j+1 << "-------" << '\n';

        std::string temp0("../data/basic/data"); temp0 += std::to_string(j+1); temp0 += ".csv";
        std::string temp1("../data/alter/data"); temp1 += std::to_string(j+1); temp1 += ".csv";
        std::string temp2("../data/basic_kah/data"); temp2 += std::to_string(j+1); temp2 += ".csv";
        std::string temp3("../data/alter_kah/data"); temp3 += std::to_string(j+1); temp3 += ".csv";

        std::string temp4("../data/heun/data"); temp4 += std::to_string(j+1); temp4 += ".csv";

        fout0.open(temp0);
        fout1.open(temp1);
        fout2.open(temp4);

        State<float> start_state1(10.0f, 0.0f, 2.0f);
        //State<KahanFloat,float> start_state2(10.0f, 0.0f, 2.0f);
        float t = 10.0f; n *= 10;

        auto state1(start_state1);
        for(unsigned i=0; i<n; i++){
            if( i % 100 == 0)
                fout0 << t/float(n)*float(i) << ' ' << state1 << '\n';
            state1.progress_basic(t/float(n));
        }
        std::cout << "progress_basic, floats - over" << '\n';

        state1 = start_state1;
        for(unsigned i=0; i<n; i++){
            if( i % 100 == 0)
                fout1 << t/float(n)*float(i) << ' ' << state1 << '\n';
            state1.progress_alter(t/float(n));
        }
        std::cout << "progress_alter, floats - over" << '\n';

        state1 = start_state1;
        for(unsigned i=0; i<n; i++){
            if( i % 100 == 0)
                fout2 << t/float(n)*float(i) << ' ' << state1 << '\n';
            state1.progress_heun(t/float(n));
        }
        std::cout << "progress_heun, floats - over" << '\n';

//        auto state2(start_state2);
//        for(unsigned i=0; i<n; i++){
//            if( i % 100 == 0)
//                fout2 << t/float(n)*float(i) << ' ' << state2 << '\n';
//            state2.progress_basic(t/float(n));
//        }
//        std::cout << "progress_basic, Kahan - over" << '\n';
//
//        state2 = start_state2;
//        for(unsigned i=0; i<n; i++){
//            if( i % 100 == 0)
//                fout3 << t/float(n)*float(i) << ' ' << state2 << '\n';
//            state2.progress_alter(t/float(n));
//        }
//        std::cout << "progress_alter, Kahan - over" << '\n';

        fout0.close();
        fout1.close();
        fout2.close();
    }
    return 0;
}