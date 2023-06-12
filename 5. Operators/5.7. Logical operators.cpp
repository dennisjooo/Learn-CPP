#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    // Logical NOT
    if (!(x > y))
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    // Logical OR
    if ((x == 5) || (y == 5))
        std::cout << "Either " << x << " or " << y << " is equal to 5\n";
    else
        std::cout << "Neither " << x << " nor " << y << " is equal to 5\n";

    // Logical AND
    if ((x > 3) && (y < 10))
        std::cout << x << " is greater than 3 and " << y << " is less than 10\n";
    else
        std::cout << x << " is not greater than 3 or " << y << " is not less than 10\n";


    return 0;
}