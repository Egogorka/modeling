

#include "Vector.h"
#include "odes/MathPendulum.h"
#include "odes/PhysPendulum.h"
#include "Writer.h"

#include "records/spiral/spiral.h"
#include "records/phys_pendulum/pendulum.h"

using namespace modeling;


int main() {
    int N = 5;
//    spiral(15.0f, 8);
    pendulum();
}