#include "Polynomial.h"

template <typename T>
T quadratic(T x, T a, T b, T c)
{
    return a + b*x + c*x*x;
}

template int quadratic(int, int, int, int);
template double quadratic(double, double, double, double);
