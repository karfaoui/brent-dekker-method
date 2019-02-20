/*
 * @Author: Kais Arfaoui 
 * @Date: 2019-02-16 10:15:11 
 * @Last Modified by:   karfaoui 
 * @Last Modified time: 2019-02-20 14:02:14 
 */

#include <iomanip>
#include <sstream>
#include <cmath>

#include "Polynome.hpp"

Polynome::Polynome(const vector<double>& coefficients) : 
    _coefficients(coefficients),
    _degree(0)
{
    _degree = coefficients.size() - 1;
}

Polynome::Polynome(const double *coefficients, size_t degree) : 
    _coefficients(vector<double>(coefficients, degree + coefficients + 1)),
    _degree(degree)
{      
    // passing an array to method decays the array to the pointer
    // thus need to pass in the size (used in degree) computed by caller !  
    

}

Polynome::Polynome(initializer_list<double> coefficients) :
    _coefficients(coefficients.begin(), coefficients.end()),
    _degree(coefficients.size()-1)
{    
    
}

Polynome::~Polynome()
{
}

double Polynome::operator()(double x)
{
    double value(0);    
    int n = 0;

    for (int i = _coefficients.size() - 1; i >= 0; i--) { 
        value += _coefficients[i] * pow(x, n);
        n++;
    }

    return value;
}

string Polynome::toString() const
{
    stringstream value;    
    size_t n = _degree;

    for (vector<double>::const_iterator i = _coefficients.begin(); i != _coefficients.end(); i++) {
        if (n == _degree) {
            value << fixed << setprecision(2) << _name << "(X) = ";

            if (*i == 1) {
                value <<"X^" << n;
            }
            else {
                value << *i << " * X^" << n;
            }
        }
        else {
            if (n) {
                if (*i)  {
                    if (*i == 1) {
                        if (n == 1) {
                            value << " + X";
                        }
                        else {
                            value << " + X^" << n;
                        }
                    }
                    else {
                        if (n == 1) {
                            if (*i > 0) {
                                value << " + ";
                            }
                            else {
                                value << " - ";
                            }

                            value << fabs(*i) << " * X";
                        }
                        else {
                            value << *i << " * X^" << n;
                        }
                    }
                    
                }
            }
            else  {
                if (*i > 0) {
                    value << " + ";
                }
                else {
                    value << " - ";
                }

                value << *i;
            }          
        }

        n--;
    }

    return value.str();
}

string Polynome::toString(double x) const 
{    
    return BaseFunctor::toString(x);
}