#include <iostream>
#include <utility> // for std::to_underlying() (C++23)

enum class Color // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
{
    red, // red is considered part of Color's scope region
    blue,
};

// Overload the unary + operator to convert Animals to the underlying type
// adapted from https://stackoverflow.com/a/42198760, thanks to Pixelchemist for the idea
constexpr auto operator+(Color a) noexcept
{
    return static_cast<std::underlying_type_t<Color>>(a);
}

constexpr std::string_view getColor(Color color)
{
    using enum Color; // bring all Color enumerators into current scope (C++20)
    // We can now access the enumerators of Color without using a Color:: prefix

    switch (color)
    {
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main()
{
    
    Color color { Color::red }; // note: red is not directly accessible, we have to use Color::red


    // Comparison of scoped enums
    if (color == Color::red) // this Color to Color comparison is okay
        std::cout << "The color is red!\n";
    else if (color == Color::blue)
        std::cout << "The color is blue!\n";
    

    // Conversion to int from scoped enums
    std::cout << static_cast<int>(color) << '\n';   // explicit conversion to int, will print 0
    std::cout << std::to_underlying(color) << '\n'; // convert to underlying type, will print 0 (C++23)
    


    // Inputs
    std::cout << "Enter a color (0 = Red, 1 = Blue): ";
    int input{};
    std::cin >> input;

    Color color2{ static_cast<Color>(input) }; // Use static_cast to convert an integer to an enum

    std::cout << +Color::red << '\n'; // use unary + to convert Color::red to its underlying type

    std::cout << "Your shirt is " << getColor(color2) << '\n';

    return 0;
}