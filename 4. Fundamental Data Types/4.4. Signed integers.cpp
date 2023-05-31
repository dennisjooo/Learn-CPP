#include <iostream>

int  main()
{
    short s;      // prefer "short" instead of "short int"
    int i;
    long l;       // prefer "long" instead of "long int"
    long long ll; // prefer "long long" instead of "long long int"

    // signed can be used with any integer type to make it explicitly signed, but it is redundant as all integer types are signed by default
    signed short ss;
    signed int si;
    signed long sl;
    signed long long sll;

    // integer overflow happens when you attempt to store a value that is outside the range of the type. This will result in undefined behavior

    // The range of values that can be stored in a signed integer is from -2^(n-1) to 2^(n-1)-1, where n is the number of bits used to store the number.

    // integer division truncates the fractional part of the result if the result is a floating point number. If both operands are integers, the result will be an integer.
    std::cout << 20 / 4 << '\n';
    std::cout << 20 / 3 << '\n';
    
    return 0;
}