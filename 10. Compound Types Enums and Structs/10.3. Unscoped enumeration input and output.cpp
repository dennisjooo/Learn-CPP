#include <iostream>

enum Color : std::int16_t // underlying type is short (you can define the type of the enum but only do it when necessary)
{
    black, // assigned 0
    red, // assigned 1
    blue, // assigned 2
    green, // assigned 3
    white, // assigned 4
    cyan, // assigned 5
    yellow, // assigned 6
    magenta, // assigned 7
    purple = -1, // assigned -1 (explicit value but should be avoided)
};

constexpr std::string_view getColor(Color color) // C++17
{
    switch (color)
    {
    case black: return "black";
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

// Teach operator<< how to print a Color
// Consider this magic for now since we haven't explained any of the concepts it uses yet
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Color color)
{
	switch (color)
	{
	case black: return out << "black";
	case red:   return out << "red";
	case blue:  return out << "blue";
	default:    return out << "???";
	}
}

// Consider this magic for now
// We pass pet by reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, Color& color)
{
    int input{};
    in >> input; // input an integer

    color = static_cast<Color>(input);
    return in;
}



int main()
{   
    // Outputs
    Color shirt{ Color::blue }; // This actually stores the integral value 2

    std::cout << "Your shirt is " << getColor(shirt) << '\n';


    // Brace initialization of enums (available only if underlying type is fixed)
    [[maybe_unused]] Color color{ 4 }; // color is now white


    // Changing variable values
    shirt = static_cast<Color>(1); // Use static_cast to convert an integer to an enum


    // Inputs
    int inputColor{};
    std::cout << "Enter a color: ";
    std::cin >> inputColor;

    [[maybe_unused]] Color color2{ static_cast<Color>(inputColor) }; // Use static_cast to convert an integer to an enum

    [[maybe_unused]] Color color3{};
    std::cout << "Enter a color: ";
    std::cin >> color3; // Use operator>> to convert an integer to an enum (magic lol)




    return 0;
}