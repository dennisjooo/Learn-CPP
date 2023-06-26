#include <iostream>

int main()
{   
    // Dynamic memory allocation with new and delete
    new int; // dynamically allocate an integer (and discard the result)

    int* ptr1{ new int (5) }; // use direct initialization
    int* ptr2{ new int { 6 } }; // use uniform initialization


    // Delete allocated memory with delete
    int* ptr{ new int }; // dynamically allocate an integer
    delete ptr; // return the memory pointed to by ptr to the operating system
    ptr = nullptr; // set ptr to be a null pointer


    // std::nothrow
    int* value { new (std::nothrow) int }; // value will be set to a null pointer if the integer allocation fails

    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }
    return 0;
}
