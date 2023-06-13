#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

consteval int greaterCE(int x, int y) // function is now consteval
{
    return (x > y ? x : y);
}

consteval auto compileTime(auto value)
{
    return value;
}


int main()
{
    constexpr int g { greater(5, 6) };            // case 1: evaluated at compile-time
    std::cout << g << " is greater!\n";

    int x{ 5 }; // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // case 2: evaluated at runtime

    std::cout << greater(5, 6) << " is greater!\n"; // case 3: may be evaluated at either runtime or compile-time

    // consteval auto compileTime 
    std::cout << greater(5, 6) << '\n';              // may or may not execute at compile-time
    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time
    std::cout << greater(x, 6) << '\n';              // we can still call the constexpr version at runtime if we wish

    return 0;
}