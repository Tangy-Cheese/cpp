#include <iostream>
#include "Polynomial.h"
#include "Fraction.h"

int main()
{
    int n_int = 5;
    int quad_int = quadratic(0, 2, 9, n_int);

    double n_double = 5.0;
    double quad_double = quadratic(0.0, 2.0, 9.0, n_double);

    std::cout << quad_double << std::endl;

    return 0;
}