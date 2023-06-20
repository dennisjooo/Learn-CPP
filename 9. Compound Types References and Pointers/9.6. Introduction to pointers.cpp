#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    // Remember int& is a lvlaue reference to an int not the address of an int

    // * is the dereference operator
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)


    // Pointers
    int* ptr;        // an uninitialized pointer (holds a garbage address)
    int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
    int* ptr3{ &x }; // a pointer initialized with the address of variable x

    std::cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)


    // Changing pointer assignment
    int y{ 7 };
    ptr = &y; // ptr now points to y

    std::cout << *ptr << '\n'; // prints 7

    *ptr = 4; // y is now 4

    std::cout << *ptr << '\n'; // prints 4


    // Size of pointers
    char* chPtr{};        // chars are 1 byte
    int* iPtr{};          // ints are usually 4 bytes
    long double* ldPtr{}; // long doubles are usually 8 or 12 bytes

    std::cout << sizeof(chPtr) << '\n'; // prints 4
    std::cout << sizeof(iPtr) << '\n';  // prints 4
    std::cout << sizeof(ldPtr) << '\n'; // prints 4


    return 0;
}