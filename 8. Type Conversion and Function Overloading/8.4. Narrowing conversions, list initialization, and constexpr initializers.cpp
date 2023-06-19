#include <iostream>

void someFcn(int i)
{
}

void print(unsigned int u) // note: unsigned
{
    std::cout << u << '\n';
}


int main()
{
    double d{ 5.0 };

    someFcn(d); // bad: implicit narrowing conversion will generate compiler warning

    // good: we're explicitly telling the compiler this narrowing conversion is intentional
    someFcn(static_cast<int>(d)); // no warning generated

    // static_cast<int> converts double to int, initializes i with int result
    int i { static_cast<int>(d) };

    std::cout << "Enter an integral value: ";
    int n{};
    std::cin >> n; // enter 5 or -5
    print(n);      // conversion to unsigned may or may not preserve value

    
    // List initialization
    int x{ 5.3 }; // warning: narrowing conversion from double to int
    
    // We can avoid literals with suffixes
    unsigned int n { 5 }; // okay (we don't need to use `5u`)
    float f { 1.2 };      // okay (we don't need to use `1.2f`)

    // We can avoid static_casts
    constexpr int n{ 5 };
    double d { n };       // okay (we don't need a static_cast here)
    short s { 5 };        // okay (there is no suffix for short, we don't need a static_cast here)

    return 0;
}