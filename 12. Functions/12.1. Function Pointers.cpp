#include <iostream>
#include <utility>
#include <functional>

int foo(int x)
{
    return x;
}

int goo()
{
    return 6;
}

// Note our user-defined comparison is the third parameter
void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int)) // or can also be written as bool comparisonFcn(int, int)
{
    // Step through each element of the array
    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex{ startIndex };

        // Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller/larger than our previously found smallest
            if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
            {
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// Here is a comparison function that sorts in ascending order
// (Note: it's exactly the same as the previous ascending() function)
bool ascending(int x, int y)
{
    return x > y; // swap if the first element is greater than the second
}

// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
    return x < y; // swap if the second element is greater than the first
}

// This function prints out the values in the array
void printArray(int* array, int size)
{
    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';
}


// Pointer function in alias
using ValidateFunction = bool(*)(int, int);

bool something(int x, int y, ValidateFunction fcnPtr)
{
    return fcnPtr(x, y);
};

int main()
{
    // fcnPtr is a pointer to a function that takes no arguments and returns an integer
    int (*fcnPtr)() { &goo };

    // Const function pointer
    int (*const fcnPtr)() { &goo };

    // Reassign fcnPtr to point to goo
    fcnPtr = &goo; // or fcnPtr = goo; since function names decay to function pointers

    // Function pointer to null pointer
    int (*fcnPtr)() { nullptr };


    // Call the function that fcnPtr points to
    int (*fcnPtr2)(int) { &foo };

    std::cout << fcnPtr2(3) << '\n'; // Implicit dereference

    std::cout << (*fcnPtr2)(3) << '\n'; // Explicit dereference


    // Uses of function pointers: function callbacks (functions passed to other functions)
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    // Sort the array in descending order using the descending() function
    selectionSort(array, 9, descending);
    printArray(array, 9);

    // Sort the array in ascending order using the ascending() function
    selectionSort(array, 9, ascending);
    printArray(array, 9);


    // Std::function (though you can also type alias this)
    std::function<int(int)> fcnPtr{ &foo };
    std::cout << fcnPtr() << '\n';

    return 0;
    
}