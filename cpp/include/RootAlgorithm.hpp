/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */

#pragma once

#include "BaseFunctor.hpp"

namespace Algorithm {

// Machine epsilon gives an upper bound on the relative error 
// due to rounding in floating point arithmetic.
const double MACHINE_EPSILON = 2.220446049250313E-016;

class RootAlgorithm {

public:
    RootAlgorithm();
    virtual ~RootAlgorithm();    
};

};