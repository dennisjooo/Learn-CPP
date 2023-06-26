#include <iostream>

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
     return (row * numberOfColumnsInArray) + col;
}

int main()
{
    int value { 5 };

    int* ptr { &value };
    std::cout << *ptr << '\n'; // Dereference pointer to int to get int value

    int** ptrptr { &ptr };
    std::cout << **ptrptr << '\n'; // dereference to get pointer to int, dereference again to get int value


    // Uses of pointers to pointers
    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count { 0 }; count < 10; ++count)
        array[count] = new int[5]; // these are our columns

    array[9][4] = 3; // This is the same as (array[9])[4] = 3;

    for (int count { 0 }; count < 10; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last


    // Flattened array
    int *array2 { new int[50] }; // a 10x5 array flattened into a single array
    array2[getSingleIndex(9, 4, 5)] = 3; // This is the same as (array[9])[4] = 3;

    delete[] array2;
}