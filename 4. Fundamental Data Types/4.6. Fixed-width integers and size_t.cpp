#include <cstdint> // for fixed-width integers
#include <cstddef> // for std::size_t
#include <iostream>

int main()
{   
    // fixed-width integers are guaranteed to have the same size on any machine
    std::int16_t i{5};
    std::cout << i;

    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';

    // Using the fast integers can improve performance, but they may not be available on all platforms. The number of bits can be different on different platforms as it is up to the compiler to choose the fastest type.
	std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
    return 0;

    // 8 bit standard integer types behave like chars in that they are signed if char is signed and unsigned char if char is unsigned

    // std::size_t is an unsigned integer type that is guaranteed to be big enough to hold the size of any object in bytes. It is defined in the <cstddef> header.
    std::cout << sizeof(std::size_t) << '\n';
}