/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */

#include <iomanip>
#include <sstream>

#include "BaseFunctor.hpp"

BaseFunctor::BaseFunctor() :
    _name("f")
{
}

BaseFunctor::~BaseFunctor()
{
}


string BaseFunctor::toString() const 
{
    return "f(x) = " + _name;
}

string BaseFunctor::toString(double x) const
{
    stringstream value;
    value << fixed << setprecision(2) << "f(" << x << ") = " << const_cast<BaseFunctor&>(*this).operator()(x);

    return value.str();
}
