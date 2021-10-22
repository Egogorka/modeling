

#include "Vector.h"
#include "odes/MathPendulum.h"
#include "odes/PhysPendulum.h"
#include "Writer.h"

#include "records/spiral/spiral.h"

using namespace modeling;


int main() {
    int N = 5;
    spiral(8);
    std::cout << 5 % 1;
//    PhysPendulum<float> ode(1.0f, 0.0f,  10.0f);
//    Writer<Vector2<float>,float> writer(&ode, std::cout, std::cout);
//
//    writer.print_euler(1.0f,2,1);
//    writer.print_heun(1.0f,2,1);

}