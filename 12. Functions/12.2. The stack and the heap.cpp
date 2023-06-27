#include <iostream>

int main()
{
    // Heap memory (dynamic allocation)
    int* ptr{ new int{ 5 } }; // allocate memory for an integer on the heap

    std::cout << *ptr << '\n'; // dereference the pointer to get its value


    // Stack memory (automatic allocation)
    int value{ 5 }; // allocate memory for an integer on the stack

    std::cout << value << '\n'; // no need to dereference the pointer to get its value
}