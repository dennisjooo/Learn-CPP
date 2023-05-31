#include <iostream>

int main()
{
    // unsigned integers can only store positive numbers (or zero)
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;

    // unsigned integer overflow is well-defined and wraps around using modulo arithmetic
    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    // since negative numbers aren't representable with unsigned integers, they wrap around to large positive values
    x = -1; // -1 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    x = -2; // -2 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    // beware of using unsigned integers because of this wrap-around behavior. Also, beware of mixing signed and unsigned integers in the same expression as the signed integer may be converted to an unsigned integer, resulting in wrap-around.
    unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n'; // 2 - 3 = 4294967295

    // infinite loops can occur if you use unsigned integers in a loop

}