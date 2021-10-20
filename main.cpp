#include "spiral/code.h"
//
//class Foo{
//
//};

//#include "spiral/KahanFloat.h"
#include "code/Vector.h"
#include "code/ODE.h"

using namespace modeling;
float omega = 1.0f;

// We think that vec[0] - phi, vec[1] - ksi;
template<typename T>
Vector2<T> matrix(const Vector2<T>& vec){
    return Vector2<T>{ vec[1], -omega*omega*vec[0] };
}

int main() {
    Vector2<float> state {10.0f, 0.0f};
    ODE_Solver<Vector2<float>, float> ode(state, matrix);
    for(unsigned i=0; i<10; ++i){
        std::cout << ode.state << '\n';
        ode.euler(0.001f);
    }

    ode.state = state;
    for(unsigned i=0; i<10; ++i){
        std::cout << ode.state << '\n';
        ode.heun(0.001f);
    }
}

