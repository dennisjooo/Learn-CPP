#include <iostream>

int main()
{   
    // Initializing a multidimensional array
    int arr[3][3]  { {1, 2, 3}, 
                     {4, 5, 6},
                     {7, 8} }; // last element of the last row is 0

    int arr2[2][1] {}; // initialize all elements to 0


    // Accessing elements of a multidimensional array
    for (int row{ 0 }; row < 3; ++row) // step through the rows in the array
    {
        for (int col{ 0 }; col < 3; ++col) // step through each element in the row
        {
            std::cout << arr[row][col];
        }
    }


    // Multidimensional array with more than two dimensions
    int arr3[3][3][3] {}; // 3D array with 3 rows, 3 columns, and 3 "depths"


    // Usage of multidimensional arrays
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    // Declare a 10x10 array
    int product[numRows][numCols]{};

    // Calculate a multiplication table
    // We don't need to calc row and col 0 since mult by 0 always is 0
    for (int row{ 1 }; row < numRows; ++row)
    {
        for (int col{ 1 }; col < numCols; ++col)
        {
            product[row][col] = row * col;
        }
     }

    // Print the table
    for (int row{ 1 }; row < numRows; ++row)
    {
        for (int col{ 1 }; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }

        std::cout << '\n';
    }

    return 0;
}