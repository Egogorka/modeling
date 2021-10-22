//
// Created by Meevere on 21.10.2021.
//

#ifndef MODELING_WRITER_H
#define MODELING_WRITER_H

#include <iostream>

#include <ODE.h>
#include <cmath>

#include "utilities.h"

using std::ostream;

namespace modeling {


    //It says that it is a Writer, but it's mostly a Controller
    template<typename Vec, typename scalar>
    class Writer {
        typedef ODE_Solver<Vec,scalar> odeSolver;

        odeSolver* ode;
        ostream& out; // Output to file
        ostream& log; // Logging in console (to check progress)

    public:
        Writer(odeSolver* ode, ostream& out, ostream& log): ode(ode), out(out), log(log) {};

        /**
         * @param t - for how much iterations it would run (in time)
         * @param N - how many (in orders of magnitude) steps
         * @param K - every K-th will be printed
         */
        void print_euler(scalar t, unsigned m, unsigned K) {
            ode->reset_state();
            unsigned long N = power(10,m);
            log << "<< start : euler, t=" << t << ", order=" << m << ", print every " << K << "-th";
            for(unsigned long i=0; i < N; i++ ){
                ode->euler(t/N);
                if (i % K == 0)
                    out << i*t/N << ' ' << ode->state << '\n';
            }
            log << " | end >>\n";
        }

        void print_heun(scalar t, unsigned m, unsigned K) {
            ode->reset_state();
            unsigned long N = power(10,m);
            log << "<< start : heun, t=" << t << ", order=" << m << ", print every " << K << "-th";
            for(unsigned long i=0; i < N; i++ ){
                ode->heun(t/N);
                if (i % K == 0)
                    out << i*t/N << ' ' << ode->state << '\n';
            }
            log << " | end >>\n";
        }
    };
}

#endif //MODELING_WRITER_H
