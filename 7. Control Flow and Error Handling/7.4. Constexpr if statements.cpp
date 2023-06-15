#include <iostream>

int main()
{
	constexpr double gravity{ 9.8 };

	if constexpr (gravity == 9.8) // now using constexpr if. This is a compile-time if statement
		std::cout << "Gravity is normal.\n";
	else
		std::cout << "We are not on Earth.\n";

    // Best practice: use constexpr if when you want to use if statements at compile time or conditional that uses a constant expression
	return 0;
}