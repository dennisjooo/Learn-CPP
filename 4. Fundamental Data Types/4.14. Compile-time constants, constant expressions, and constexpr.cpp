#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

int main()
{   
    // Compile-time constants
	const int x { 3 };  // x is a compile-time const
	const int y { 4 };  // y is a compile-time const

	const int z { x + y }; // x + y is a constant expression, so z is compile-time const

	std::cout << z << '\n';

    // Runtime constants
    const int i{ 3 };           // x is a compile time constant

    const int j{ getNumber() }; // y is a runtime constant

    const int k{ i + j };       // x + y is a runtime expression
    std::cout << k << '\n';     // this is also a runtime expression

    // Constexpr is a compile-time constant
    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

	return 0;
}