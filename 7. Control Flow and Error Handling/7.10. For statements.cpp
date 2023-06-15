#include <iostream>
#include <cstdint> // for fixed-width integers

// returns the value base ^ exponent -- watch out for overflow!
std::int64_t pow(int base, int exponent)
{
    std::int64_t total{ 1 };

    for (int count{ 0 }; count < exponent; ++count)
        total *= base;

    return total;
}

int main()
{
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << count << ' ';

    std::cout << '\n';

    return 0;

    pow(2, 3); // 8 (2 * 2 * 2)


    // Decrement for loop
    for (int count{ 9 }; count >= 0; --count)
        std::cout << count << ' ';

    std::cout << '\n';


    // Ommitted init-statement
    int count{ 0 };
    for ( ; count < 10; ) // no init-statement or end-expression
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << '\n';


    // Multiple init-statements
    for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';


    // Nested for loops
    for (char c{ 'a' }; c <= 'e'; ++c) // outer loop on letters
	{
		std::cout << c; // print our letter first

		for (int i{ 0 }; i < 3; ++i) // inner loop on all numbers
			std::cout << i;

		std::cout << '\n';
	}
    return 0;
}