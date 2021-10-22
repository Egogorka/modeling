//
// Created by Meevere on 22.10.2021.
//

#include "utilities.h"

unsigned long modeling::power(unsigned long in, unsigned power){
    auto out = 1;
    for(unsigned i=0; i<power; i++){
        out *= in;
    }
    return out;
}