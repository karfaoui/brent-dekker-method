/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */
#pragma once

#include "BaseFunctor.hpp"
#include "RootAlgorithm.hpp"

namespace Algorithm {

class BrentsMethod : public RootAlgorithm {

public:
    BrentsMethod();
    virtual ~BrentsMethod();

public:
    static double root(double a, double b, BaseFunctor& f);
};

};
