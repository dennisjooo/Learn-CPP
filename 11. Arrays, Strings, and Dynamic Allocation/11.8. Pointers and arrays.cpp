#include <iostream>

// parameter ptr contains a copy of the array's address
void changeArray(int* ptr)
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

int main()
{
    int array[5]{ 9, 7, 5, 3, 1 };

    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    // Deferencing an array returns the first element (element 0)
    std::cout << *array; // will print 9!

    // Pointer-to-array can be used to access the array
    int* ptr{ array };
    std::cout << *ptr << '\n'; // will print 9 


    // Difference between array and pointer
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length
    std::cout << sizeof(ptr) << '\n'; // will print sizeof(int*)


    // Pass by address
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "Element 0 has value: " << array[0] << '\n';

    changeArray(array);

    std::cout << "Element 0 has value: " << array[0] << '\n';

    return 0;

}