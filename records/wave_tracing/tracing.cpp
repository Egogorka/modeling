//
// Created by meeve on 13.11.2021.
//

#include "tracing.h"

#include "Vector.h"
#include "typedefs.h"

#include "odes/WaveTracing.h"
#include "Writer.h"

#include <fstream>

using namespace modeling;
const std::string PATH = "../records/wave_tracing/data/";

float n_e(Vector2f r){
    return 1 + r[0];
}

Vector2f grad_n_e(Vector2f r){
    return {1,0};
}

int tracing(){
    int N = 6;
    float time = 10.0f;

    Vector4<float> state{0,0,
                   (float)cos(1), (float)sin(1)};

    WaveTracing<float> ode1(2.0f, n_e, grad_n_e, state);

    std::ofstream fout;
    Writer<Vector4<float>, float> writer1(&ode1, fout, std::cout);

    std::cout << "Basic float euler block opened\n";
    for(int i=1; i<=20; i++) {
        ode1.start_state = Vector4<float>
                {0, 0,
                 (float)cos(-0.5*i), (float)sin(-0.5*i)};
        std::string temp;
        temp = PATH + "euler/data" + std::to_string(i) + ".csv";
        fout.open(temp);
        writer1.print_euler(time, N, 100);
        fout.close();
    }
    std::cout << "Basic float block closed\n";
    return 0;
}