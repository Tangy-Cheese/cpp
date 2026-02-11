#include "Fraction.h"
#include <string>
#include <numeric> // You may use std::gcd to calculate a greatest common divisor.

Fraction::Fraction(int a, int b){
    numerator = a;
    denominator = b;
}

Fraction Fraction::reciprocal(){
    return Fraction(denominator, numerator);
}

Fraction Fraction::multiply(int a){
    return Fraction(numerator * a, denominator);
}

std::string Fraction::toString(){
    if (numerator==0){
        return std::to_string(0);
    }
    return std::to_string(numerator/denominator);
}

double Fraction::toDouble(){
    return numerator/denominator;
}