//
// Created by Meevere on 22.10.2021.
//

#include "pendulum.h"

#include "Vector.h"
#include "odes/PhysPendulum.h"
#include "Writer.h"

#include <fstream>

using namespace modeling;
const std::string PATH = "../records/phys_pendulum/data/";

int pendulum(){
    int N = 7;
    float time = 15.0f;

    PhysPendulum<float> ode1(1.0f, 0.0f,  0.1f);

    std::ofstream fout;
    Writer<Vector2<float>, float> writer1(&ode1, fout, std::cout);

    std::cout << "Basic float block opened\n";
    for(int i=1; i<=20; i++) {
        ode1.start_state = Vector2f{0.0f, 0.2f*i};
        std::string temp;
        temp = PATH + "euler/data" + std::to_string(i) + ".csv";
        fout.open(temp);
        writer1.print_euler(time, N, 1000);
        fout.close();

//        temp = PATH + "heun/data" + std::to_string(i) + ".csv";
//        fout.open(temp);
//        writer1.print_heun(time, N, 1000);
//        fout.close();
    }
    std::cout << "Basic float block closed\n";


    std::cout << "Second \'eye\' block opened\n";
    for(int i=1; i<=10; i++) {
        ode1.start_state = Vector2f{6.28f, 0.2f*i};
        std::string temp;
        temp = PATH + "euler_2/data" + std::to_string(i) + ".csv";
        fout.open(temp);
        writer1.print_euler(time, N, 1000);
        fout.close();

//        temp = PATH + "heun/data" + std::to_string(i) + ".csv";
//        fout.open(temp);
//        writer1.print_heun(time, N, 1000);
//        fout.close();
    }
    std::cout << "Block closed\n";

//    PhysPendulum<KahanFloat> ode2(1.0f, 0.0f,  0.1f);
//    Writer<Vector2<KahanFloat>, float> writer2(&ode2, fout, std::cout);
//
//    std::cout << "Kahan float block opened\n";
//    for(int i=1; i<=10; i++) {
//        ode2.start_state = Vector2kf{0.0f, 0.1f*i};
//        std::string temp;
//        temp = PATH + "euler_kah/data" + std::to_string(i) + ".csv";
//        fout.open(temp);
//        writer2.print_euler(time, N, 1000);
//        fout.close();
//
//        temp = PATH + "heun_kah/data" + std::to_string(i) + ".csv";
//        fout.open(temp);
//        writer2.print_heun(time, N, 1000);
//        fout.close();
//    }
//    std::cout << "Kahan float block closed\n";
    return 0;
}