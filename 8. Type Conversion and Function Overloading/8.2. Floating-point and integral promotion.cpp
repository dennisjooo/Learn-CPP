#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printDouble(double d)
{
    std::cout << d << '\n';
}

int main()
{
    printInt(5.5); // double value 5.5 implicitly converted to type int
    printInt(5.3 + 0.2); // double value 5.5 implicitly converted to type int
    printInt('A'); // char value 'A' implicitly converted to type int
    printInt(true); // bool value true implicitly converted to type int
    printInt(0.3); // double value 0.3 implicitly converted to type int
    printInt(0.999999999); // double value 0.999999999 implicitly converted to type int


    // Floating point promotion
    printDouble(5.0); // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double


    // Integral promotion
    short s{ 3 }; // there is no short literal suffix, so we'll use a variable for this one
    printInt(s); // numeric promotion of short to int

    printInt('a'); // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int
}