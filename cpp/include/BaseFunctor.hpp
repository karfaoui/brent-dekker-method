/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */

#pragma once

#include "pch.h"

class BaseFunctor {

public:
  BaseFunctor();
  virtual ~BaseFunctor();

public:
  void setName(const string& value) 
    { _name = value; }

  const string& name() const
    { return _name; }
    
public:
  virtual double operator() (double) = 0;

public:
  virtual string toString() const;
  virtual string toString(double x) const;  

protected:
  string _name;
};