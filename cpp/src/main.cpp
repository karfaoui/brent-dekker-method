/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */

#include<iostream>

#include "BrentsMethod.hpp"
#include "Polynome.hpp"
#include "Functions.hpp"

using namespace std;


int main(){
    Function F; 

    // Test 1
    auto f1 = F("sin(x)-0.5*x");    
    auto z = Algorithm::BrentsMethod::root(1.0, 2.0, *f1);
    cout << "Root of " << f1->toString() << " in [1,2] is " << z << endl;    

    // Test 2
    auto f2 = F("2*x-exp(-x)");    
    z = Algorithm::BrentsMethod::root(0.0, 1.0, *f2);
    cout << "Root of " << f2->toString() << " in [0,1] is " << z << endl; 

    // Test 3
    Polynome poly({1, 1, -5, 3}); 

    z = Algorithm::BrentsMethod::root(-5, -2, poly);
    cout << "Root of " << poly.toString() << " in [-5,-2] is " << z << endl; 

    z = Algorithm::BrentsMethod::root(0, 3, poly);
    cout << "Root of " << poly.toString() << " in [0,3] is " << z << endl; 

    
}