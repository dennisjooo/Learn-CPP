#include <iostream>

void print_int(int x) // print now takes an int parameter
{
	std::cout << x;
}

void print_doub(double x)
{
    std::cout << x;
}

int main()
{
	// print_int(5.5); // warning: we're passing in a double value, THIS IS BAD

    print_doub(5); // warning: we're passing in an int value, this is fine, the int will be implicitly converted to a double

    std::cout << std::endl;

    // Explicit type conversion (casting)
    print_int( static_cast<int>(5.5) ); // explicitly convert double value 5.5 to an int

    std::cout << std::endl;

    // Int to Char
    char ch{ 97 }; // 97 is ASCII code for 'a'

    std::cout << ch << '\n'; // print character a
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // print value of variable ch as an int
    
    // Addressing the fixed width 8-bit integer type
    std::int8_t myint{65};
    std:: cout << myint << '\n'; // will print A
    std::cout << static_cast<int>(myint) << '\n'; // will always print 65

	return 0;
}