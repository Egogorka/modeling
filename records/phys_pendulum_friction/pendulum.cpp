//
// Created by meeve on 13.11.2021.
//

#include "pendulum.h"

#include "Vector.h"
#include "typedefs.h"

#include "odes/PhysPendulumFriction.h"
#include "Writer.h"

#include <fstream>

using namespace modeling;
const std::string PATH = "../records/phys_pendulum_friction/data/";

int pendulum_friction() {
    int N = 5;
    float time = 15.0f;

    PhysPendulumFriction<float> ode1(1.0f, 0.3f, 0.0f,  0.1f);

    std::ofstream fout;
    Writer<Vector2<float>, float> writer1(&ode1, fout, std::cout);

    std::cout << "Basic float euler block opened\n";
    for(int i=1; i<=20; i++) {
        ode1.start_state = Vector2f{0.0f, 0.2f*i};
        std::string temp;
        temp = PATH + "euler/data" + std::to_string(i) + ".csv";
        fout.open(temp);
        writer1.print_euler(time, N, 100);
        fout.close();
    }
    std::cout << "Basic float block closed\n";

    std::cout << "Basic float heun block opened\n";
    for(int i=1; i<=20; i++) {
        ode1.start_state = Vector2f{0.0f, 0.2f*i};
        std::string temp;
        temp = PATH + "heun/data" + std::to_string(i) + ".csv";
        fout.open(temp);
        writer1.print_heun(time, N, 100);
        fout.close();
    }
    std::cout << "Basic float block closed\n";

    return 0;
}