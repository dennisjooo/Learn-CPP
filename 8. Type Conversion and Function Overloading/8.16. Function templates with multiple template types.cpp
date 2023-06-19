#include <iostream>

template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}

// C++20 Auto-deduced arguments (the same as template argument deduction)
auto min(auto x, auto y)
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << max(static_cast<double>(2), 3.5) << '\n'; // convert our int to a double so we can call max(double, double)

    // we've explicitly specified type double, so the compiler won't use template argument deduction
    std::cout << max<double>(2, 3.5) << '\n';

    std::cout << min(2, 3.5) << '\n'; // min() deduces template arguments (C++20)

    return 0;
}