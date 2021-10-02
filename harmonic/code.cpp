//
// Created by meeve on 25.09.2021.
//

#include <iostream>
#include <fstream>

int sem_2() {
    std::ofstream fout1, fout2;
    fout1.open("./data1.csv");
    fout2.open("./data2.csv");

    unsigned long N = 10000000;

    float out1 = 0, out2 = 0;

    int ln1 = 0, ln2 = 0;

    for(unsigned long i=1; i<N; ++i){
        out1 += 1/float(i);
        out2 += 1/float(N-i);

        //        int temp = (int)(2*std::log(i));
        //        if (temp != fout1) {
        fout1 << i << ' ' << out1 << '\n';
        //        }
        // СУММИРОВАНИЕ КЭХЕНА!!
        //
        fout2 << N-i << ' ' << out2 << '\n';
    }

    fout1.close();
    fout2.close();
    return 0;
}