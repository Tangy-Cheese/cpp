#pragma once
#include <string>

class Fraction{

    public:
    Fraction(int a, int b);

    Fraction reciprocal();

    Fraction multiply(int a);

    std::string toString();

    double toDouble();

    private:
    int numerator;
    int denominator;

};