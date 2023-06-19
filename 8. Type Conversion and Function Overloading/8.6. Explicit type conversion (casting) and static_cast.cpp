#include <iostream>

int main()
{
    // C-style cast (avoid this in C++)
    int x { 10 };
    int y { 4 };


    double d { (double)x / y }; // convert x to a double so we get floating point division
    std::cout << d; // prints 2.5


    // Static cast
    char c { 'a' };
    std::cout << c << ' ' << static_cast<int>(c) << '\n'; // prints a 97
    
    // static cast x to a double so we get floating point division
    double d { static_cast<double>(x) / y };
    std::cout << d; // prints 2.5

    // Narrowing conversions using static_cast
    int i { 48 };

    // explicit conversion from int to char, so that a char is assigned to variable ch
    char ch { static_cast<char>(i) };

    int i { 100 };
    i = static_cast<int>(i / 2.5);

    return 0;
}