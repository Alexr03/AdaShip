//
// Created by alexr on 11/01/2021.
//

#include "mathshelper.h"
#include <list>
#include <vector>
#include <random>

using namespace std;

int mathshelper::generatePickedNumber(int maxNumber) {
    // Random number generator based on random device
    std::random_device rdev;
    std::mt19937 rgen(rdev());
    // Distribute by defining a minimum number and max number.
    std::uniform_int_distribution<int> idist(1, maxNumber); //(inclusive, inclusive)
    return idist(rgen);
}