#include <iostream>

int main()
{
    int x{ 1 };
    int y{ 2 };
    int z{}, a{}, b{};

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand

    z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
    z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.


    // Conditional operator
    bool larger = (x > y) ? x : y;
    return 0;

    // Another use of the ternary operator
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';
}