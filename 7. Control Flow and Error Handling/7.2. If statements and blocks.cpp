#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x > 10)
        std::cout << x << " is greater than 10\n";
    else
        std::cout << x << " is not greater than 10\n";
        std::cout << "This is not part of the if statement\n";

    // The same with if block, without block, the next line is not part of the if statement
    if (x > 10)
    {
        std::cout << x << " is greater than 10\n";
    }
    else
    {
        std::cout << x << " is not greater than 10\n";
        std::cout << "This is part of the if statement\n";
    }

    return 0;
}