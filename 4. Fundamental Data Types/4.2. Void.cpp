#include <iostream>

void writeValue(int x) // void here means no return value
{
    std::cout << "The value of x is: " << x << '\n';
    // no return statement, because this function doesn't return a value

    // you cannot return a value from a void function, neither can you declare a void variable
}