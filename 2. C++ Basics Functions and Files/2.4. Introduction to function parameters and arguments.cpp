#include <iostream>

int add(int x, int y) // x and y are parameters
{
    return x + y;
}

int multiply(int z, int w) // z and w are parameters
{
    return z * w;
}

int doubleNumber(int x)
{
    return x * 2;
}

int getUserNumber()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    return x;
}

int main()
{
    std::cout << add(4, 5) << '\n'; // within add() x=4, y=5, so x+y=9
    std::cout << add(1 + 2, 3 * 4) << '\n'; // within add() x=3, y=12, so x+y=15

    int a{ 5 };
    std::cout << add(a, a) << '\n'; // evaluates (5 + 5)

    std::cout << add(1, multiply(2, 3)) << '\n'; // evaluates 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << '\n'; // evaluates 1 + (2 + 3)

    std::cout << doubleNumber(5) << '\n'; // evaluates 5 * 2

    int x{ getUserNumber() }; // getUserNumber() returns an integer, which we store in x

    std::cout << x << " doubled is: " << doubleNumber(x) << '\n';

    return 0;
}