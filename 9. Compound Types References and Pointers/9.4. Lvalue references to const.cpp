#include <iostream>

int main()
{
    const int x { 5 };    // x is a non-modifiable lvalue
    const int& ref { x }; // okay: ref is a an lvalue reference to a const value but we can't change the value of x using ref

    std::cout << ref << '\n'; // okay: we can access the const object

    const int& ref2 { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref

    std::cout << ref2 << '\n'; // prints 5

    return 0;
}