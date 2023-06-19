#include <iostream>

// Overloading function use number and type of arguments to differentiate between functions

// Different number of arguments
int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

// Different type of arguments (const and non-const are treated the same, same with type aliases)
double add(double x, double y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2) << '\n'; // calls add(int, int)
    std::cout << add(1, 2, 3) << '\n'; // calls add(int, int, int)
    std::cout << add(1.2, 3.4) << '\n'; // calls add(double, double)

    return 0;
}