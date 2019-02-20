/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */

#include "BaseFunctor.hpp"

#include <map>
#include <cmath>
#include <memory>

/**
 * The null or zero function.
 */
class F : public BaseFunctor {  
    public:
        F() {};
        virtual ~F() {};          
    public:
        virtual double operator()(double x) {
            return 0.0;
        }
};

/**
 * The function f(x) = sin ( x ) - 0.5 * x
 */
class F1 : public BaseFunctor {
   
    public:
        virtual double operator()(double x) {
            return sin ( x ) - 0.5 * x;
        }
};

/**
 * The function f(x) = 2 * x - exp ( -x )
 */
class F2 : public BaseFunctor {
   
    public:
        virtual double operator()(double x) {
            return 2.0 * x - exp ( - x );
        }
};

/**
 * Sample function generator !
 */ 
class Function {
    public:
        Function() {};
        virtual ~Function() {};

    public:
        unique_ptr<BaseFunctor> operator()(const string& f) {
            if (f == "sin(x)-0.5*x") {
                unique_ptr<F1> f1(new F1());
                f1->setName(f);
                return f1;
            }
            else if (f == "2*x-exp(-x)") {
                unique_ptr<F2> f2(new F2());
                f2->setName(f);
                return f2;
            }
            
            unique_ptr<F> g(new F());
            return g;                
        }
};




