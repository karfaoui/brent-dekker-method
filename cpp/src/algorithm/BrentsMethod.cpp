#include <cmath>
#include "BrentsMethod.hpp"

using namespace Algorithm;


BrentsMethod::BrentsMethod()
{
}

BrentsMethod::~BrentsMethod()
{
}

double BrentsMethod::root(double a, double b, BaseFunctor &f)
{      
    double t = MACHINE_EPSILON;
    double tolerance = 0.0;

    double m = 0.0;
    double p = 0.0;
    double q = 0.0;
    double r = 0.0;
    double s = 0.0;
    
    double a1 = a;
    double b1 = b;
    double fa = f(a1);
    double fb = f(b1);

    double c = a1;
    double fc = fa;
    double e = b1 - a1;
    double d = e;

    while (true)
    {
        if (fabs(fc) < fabs(fb))
        {
            a1 = b1;
            b1 = c;
            c = a1;
            fa = fb;
            fb = fc;
            fc = fa;
        }

        tolerance = 2.0 * MACHINE_EPSILON * fabs(b1) + t;
        m = 0.5 * (c - b1);

        if ((fabs(m) <= tolerance) || (fb == 0.0))
        {
            break;
        }

        if ((fabs(e) < tolerance) || (fabs(fa) <= fabs(fb)))
        {
            e = m;
            d = e;
        }
        else
        {
            s = fb / fa;

            if (a1 == c)
            {
                p = 2.0 * m * s;
                q = 1.0 - s;
            }
            else
            {
                q = fa / fc;
                r = fb / fc;
                p = s * (2.0 * m * q * (q - r) - (b1 - a1) * (r - 1.0));
                q = (q - 1.0) * (r - 1.0) * (s - 1.0);
            }

            if (p > 0.0)
            {
                q = -q;
            }
            else
            {
                p = -p;
            }

            s = e;
            e = d;

            if ((2.0 * p < 3.0 * m * q - fabs(tolerance * q)) && (p < fabs(0.5 * s * q)))
            {
                d = p / q;
            }
            else
            {
                e = m;
                d = e;
            }
        }

        a1 = b1;
        fa = fb;

        if (tolerance < fabs(d))
        {
            b1 += d;
        }
        else if (0.0 < m)
        {
            b1 += tolerance;
        }
        else
        {
            b1 = b1 - tolerance;
        }

        fb = f(b1);

        if ((0.0 < fb && 0.0 < fc) || (fb <= 0.0 && fc <= 0.0))
        {
            c = a1;
            fc = fa;
            e = b1 - a1;
            d = e;
        }
    }

    return b1;
}
