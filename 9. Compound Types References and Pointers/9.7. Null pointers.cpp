#include <iostream>

int main()
{
    int* ptr {}; // ptr is a null pointer, and is not holding an address

    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr


    int* ptr2 { nullptr }; // ptr2 is a null pointer, and is not holding an address

    ptr2 = &x; // ptr2 now pointing at object x (no longer a null pointer)

    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer again

    // DO NOT DEREFERENCE A NULL POINTER



    // Checking for null pointers
    
    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if (ptr) // implicit conversion to Boolean
        std::cout << "ptr is non-null\n";
    else
        std::cout << "ptr is null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean

    return 0;
}