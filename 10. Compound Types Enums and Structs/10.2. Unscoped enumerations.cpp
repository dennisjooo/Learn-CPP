#include <iostream>

// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon


// Prefer putting enums in a namespace
namespace color
{
    enum Color
    {
        red,
        green,
        blue,
    };
}

int main()
{
    // Define a few variables of enumerated type Color
    Color apple { red };   // my apple is red
    Color shirt { green }; // my shirt is green
    Color cup { blue };    // my cup is blue

    Color flower { Color::blue }; // we can also use the scope resolution operator to access the enum

    color::Color eyes { color::green }; // we can also use the namespace to access the enum


    if (shirt != blue)
    {
        std::cout << "The color of my shirt is not blue\n";
    }
    else
    {
        std::cout << "The color of my shirt is blue\n";
    }


    return 0;
}