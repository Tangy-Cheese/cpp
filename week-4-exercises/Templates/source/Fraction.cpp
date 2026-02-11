#include "Fraction.h"
#include <numeric>

Fraction::Fraction(int a, int b) : numerator(a), denominator(b) 
{
    Simplify();
}

Fraction Fraction::Multiply(Fraction other)
{
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

void Fraction::Simplify()
{
    int n;
    while((n = std::gcd(numerator, denominator)) != 1)
    {
        numerator /= n;
        denominator /= n;
    }
}

Fraction Fraction::Add(Fraction other)
{
    int new_num = numerator * other.denominator + other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Fraction(new_num, new_den);
}

std::string Fraction::toString() const
{
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
    out << f.toString();
    return out;
}