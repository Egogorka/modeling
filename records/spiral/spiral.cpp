//
// Created by Meevere on 21.10.2021.
//

#include "spiral.h"

#include "Vector.h"
#include "odes/MathPendulum.h"
#include "Writer.h"

#include <fstream>


using namespace modeling;
const std::string PATH = "../records/spiral/data/";

int spiral(const int N){

    MathPendulum<float> ode1(1.0f, 0.0f,  10.0f);

    std::ofstream fout;
    std::cout << "Basic float block opened\n";
    Writer<Vector2<float>, float> writer1(&ode1, fout, std::cout);
    for(int i=0; i<N; i++) {
        std::string temp;
        temp = PATH + "euler/data" + std::to_string(i+1) + ".csv";
        fout.open(temp);
        writer1.print_euler(5.0f, i+1, i > 4 ? power(10,i-4) : 1);
        fout.close();

        temp = PATH + "heun/data" + std::to_string(i+1) + ".csv";
        fout.open(temp);
        writer1.print_heun(5.0f, i+1, i > 4 ? power(10,i-4) : 1);
        fout.close();
    }
    std::cout << "Basic float block closed\n";

    MathPendulum<KahanFloat> ode2(1.0f, 0.0f,  10.0f);
    Writer<Vector2<KahanFloat>, float> writer2(&ode2, fout, std::cout);
    std::cout << "Kahan float block opened\n";
    for(int i=0; i<N; i++) {
        std::string temp;
        temp = PATH + "euler_kah/data" + std::to_string(i+1) + ".csv";
        fout.open(temp);
        writer2.print_euler(5.0f, i+1, i > 4 ? power(10,i-4) : 1);
        fout.close();

        temp = PATH + "heun_kah/data" + std::to_string(i+1) + ".csv";
        fout.open(temp);
        writer2.print_heun(5.0f, i+1, i > 4 ? power(10,i-4) : 1);
        fout.close();
    }
    std::cout << "Kahan float block closed\n";
    return 0;
}


