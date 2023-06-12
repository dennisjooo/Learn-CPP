#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

int main(){
    int x, y, z, w;

    x = (y + z + w);   // instead of this
    x = y + z + w;     // it's okay to do this

    x = ((y || z) && w); // instead of this
    x = (y || z) && w;   // it's okay to do this

    x = (y *= z); // expressions with multiple assignments still benefit from parenthesis

    // Unspecified order of evaluation
    std::cout << getValue() + (getValue() * getValue()); // a + (b * c)

    int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third

    std::cout << a + (b * c); // order of eval doesn't matter now
    return 0;
}