/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */
#pragma once

#include <string>
#include <vector>
#include <initializer_list>

#include "BaseFunctor.hpp"

class Polynome : public BaseFunctor
{
public:  
  Polynome(const vector<double>& coefficients);
  Polynome(const double *coefficients, size_t degree); 
  Polynome(initializer_list<double> coefficients);

  virtual ~Polynome();

public:
  double operator()(double);

public:
  string toString() const;
  string toString(double x) const;

public:
  size_t degree() const
    { return _degree; }  

private:
  // coefficients must be in increasing order !
  vector<double> _coefficients;
  
  // degree
  size_t _degree;
};