#include <iostream>

int main()
{
    std::cout << "Enter a positive integer: ";
    int length{};
    std::cin >> length;

    int* array{ new int[length]{} }; // use array new.  Note that length does not need to be constant! the same as calling new[]

    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array

    // we don't need to set array to nullptr/0 here because it's going out of scope immediately after this anyway


    // Initializing dynamically allocated arrays
    int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array before C++11
    int* array{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array since C++11
    // To prevent writing the type twice, we can use auto. This is often done for types with long names.
    auto* array{ new int[5]{ 9, 7, 5, 3, 1 } };

    delete[] array;
    delete[] fixedArray;

    int fixedArray[]{ 9, 7, 5, 3, 1 }; // initialize a fixed array in C++11
    char fixedArray[]{ "Hello, world!" }; // initialize a fixed array in C++11

    delete[] fixedArray;

    return 0;
}