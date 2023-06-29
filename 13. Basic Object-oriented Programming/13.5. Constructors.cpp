#include <iostream>
#include <cassert>

class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    // Default constructor (will be generated if not declared)
    Fraction(int numerator=0, int denominator=1)
    {
        assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;
    }


    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Date
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    // Tell the compiler to create a default constructor, even if
    // there are other user-provided constructors.
    Date() = default;

    Date(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
};

int main()
{
    Fraction frac{}; // calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';


    // Value initialization
    Fraction frac1{}; // equivalent to Fraction frac1;


    // Direct initialization
    Fraction frac2{ 5, 6 }; // calls Fraction(int, int) constructor
    return 0;


    // Default constructor
    Date date{}; // date is initialized to Jan 1st, 1900
    Date today{ 2020, 10, 14 }; // today is initialized to Oct 14th, 2020
}