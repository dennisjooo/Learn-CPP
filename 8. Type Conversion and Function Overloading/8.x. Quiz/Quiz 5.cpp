#include <iostream>

template <typename T, typename U>
auto add(T x, U y)
{
    return x + y;
}

template <typename T, typename U>
auto mult(T x, U y)
{
    return x * y;
}

// Abbreviated function template (C++20)
auto sub(auto x, auto y)
{
    return x - y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

    std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}