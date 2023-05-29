#include <iostream>

void doNothing(int&) // Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}

/* 
    Undefined behavior is when the C++ standard doesn't say what the output should be, and the compiler doesn't do anything to make the output sensible. Could be the result of a compiler optimization, or could be something else.

    Implementation-defined behavior is when the C++ standard doesn't say what the output should be. Could be the result of a compiler optimization, or could be something else. But the compiler documents what it does.

    Unspecified behavior is when the C++ standard doesn't say what the output should be, but the compiler does something to make the output sensible. Could be the result of a compiler optimization, or could be something else.
*/

int main()
{
    // define an integer variable named x
    int x; // this variable is uninitialized

    doNothing(x); // make the compiler think we're assigning a value to this variable

    // print the value of x to the screen (who knows what we'll get, because x is uninitialized)
    std::cout << x << '\n';

    std::cout << sizeof(int); // print how many bytes of memory an int value takes

    return 0;
}