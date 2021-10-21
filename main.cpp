#include "spiral/code.h"
//
//class Foo{
//
//};

#include "Vector.h"
#include "odes/MathPendulum.h"

using namespace modeling;

int main() {
    MathPendulum<float> ode(1.0f, 10.0f,  0.0f);

    for(unsigned i=0; i<10; ++i){
        std::cout << ode.state << '\n';
        ode.euler(0.00001f);
    }

    ode.reset_state();
    for(unsigned i=0; i<10; ++i){
        std::cout << ode.state << '\n';
        ode.heun(0.00001f);
    }
}

