#include <iostream>

int main()
{
    std::cout << 5 << '\n'; // print the value of a literal. Literal cannot be changed.

    int x { 5 };
    std::cout << x << '\n'; // print the value of a variable. Variable can be changed.
    return 0;

    std::cout << 1 + 2 << '\n'; // print the value of an expression

    std::cout << (x = 2) << '\n'; // assigns 2 to x, then prints x (which is 2)

    return 0;
}