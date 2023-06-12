#include <iostream>
#include <cmath>
#include <cstdint> // for std::int64_t
#include <cassert> // for assert

bool isOdd(int x)
{
    // Using (x % 2) == 1 is a common mistake when trying to check if a value is odd because it doesn’t work for negative values.
    // For example, -5 % 2 == -1, which is not equal to 1.

    return (x % 2) != 0; // could also write return !(x % 2)
}


// note: exp must be non-negative
std::int64_t powint(std::int64_t base, int exp)
{
	assert(exp >= 0 && "powint: exp parameter has negative value");

	std::int64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

bool isEven(int x)
{
    return (x % 2) == 0;
}

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "The remainder is: " << x % y << '\n';

	if ((x % y) == 0)
		std::cout << x << " is evenly divisible by " << y << '\n';
	else
		std::cout << x << " is not evenly divisible by " << y << '\n';


    // isOdd() returns true if x is odd, false otherwise
    std::cout << x << " is " << (isOdd(x) ? "odd" : "even") << '\n';

    // isEven() returns true if x is even, false otherwise
    std::cout << x << " is " << (isEven(x) ? "even" : "odd") << '\n';

    // Exponentiation
    std::cout << "Enter a base: ";
    int base{};
    std::cin >> base;

    std::cout << x << " raised to the " << y << " power is: " << pow(base, y) << '\n';

    // Exponentiation using a loop
    std::cout << x << " raised to the " << y << " power is: " << powint(base, y) << '\n';
	return 0;
}