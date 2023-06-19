#include <iostream>

// Function with auto must be forward declared and must return the same type for all calls (can't return int or double using if/else)
auto add(int x, int y)
{
    return x + y;
}

// Trail return type syntax, this can be forward declared
auto divide(double x, double y) -> double;

int main()
{
    auto sum { add(5, 6) }; // add() returns an int, so sum's type will be deduced to int
    std::cout << sum << '\n';

    auto result { divide(5.0, 6.0) }; // divide() returns a double, so result's type will be deduced to double
    return 0;
}

auto divide(double x, double y) -> double
{
    return x / y;
}