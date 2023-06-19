#include <iostream>

void print(char c, int x)
{
	std::cout << 'a' << '\n';
}

void print(char c, double x)
{
	std::cout << 'b' << '\n';
}

void print(char c, float x)
{
	std::cout << 'c' << '\n';
}

int main()
{
	print('x', 'a');
}