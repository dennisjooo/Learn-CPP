#include <iostream>
#include "io.h"

int readNumber()
{
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    return x;
}

int writeAnswer(int x, int y)
{
    std::cout << x << " + " << y << " = " << x + y << std::endl;
    return 0;
}
