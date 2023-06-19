#include <iostream>

int add(int x, int y) // Integer version of add()
{
    return x + y;
}

double add(double x, double y) // Double version of add()
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}