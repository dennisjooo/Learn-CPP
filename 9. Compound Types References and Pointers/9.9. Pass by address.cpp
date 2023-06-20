#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{   

    if (!ptr) // if ptr is a null pointer, early return back to the caller
        return;

    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example
{
    if (!ptr) // if ptr is a null pointer, early return back to the caller
        return;

    *ptr = 6; // change the value to 6
}


int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str


    // Modifying values through pointers
    int x{ 5 };
    std::cout << x << '\n';

    changeValue(&x); // note: we are passing a pointer to x
    std::cout << x << '\n';


    return 0;
}

// Author seems to recommend "pass by reference" as the default, and "pass by address" as a backup for when you can't use "pass by reference".