#include <iostream>

int main()
{
	try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler (good for production, bad for debugging)
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
}