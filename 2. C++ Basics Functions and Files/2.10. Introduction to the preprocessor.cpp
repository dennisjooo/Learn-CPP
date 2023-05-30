#include <iostream> // this is a preprocessor directive. It tells the preprocessor to include the iostream standard file. The preprocessor will replace this line with the entire contents of the iostream standard file before the compiler processes the code.

#define MY_NAME "Alex" // this is a macro definition. The preprocessor will replace every occurrence of MY_NAME with "Alex" before the compiler processes the code. Object-like macros are usually written in all caps to distinguish them from variables.

#define NOTHING // macros can also be defined without a value. In this case, the preprocessor will replace every occurrence of NOTHING with nothing.

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    #ifdef MY_NAME // ifdef tells the preprocessor to check if MY_NAME has been defined. If it has, the code between #ifdef and #endif will be included. Otherwise, it will be excluded.
        std::cout << "This will print!\n";
    #endif

    #ifndef NOTHING // ifndef tells the preprocessor to check if NOTHING has not been defined. If it hasn't, the code between #ifndef and #endif will be included. Otherwise, it will be excluded.
        std::cout << "This will also print!\n";
    #endif

    #if 0 // if tells the preprocessor to check if the expression evaluates to true. If it does, the code between #if and #endif will be included. Otherwise, it will be excluded. In this case, the expression is 0, which is always false, so the code will always be excluded.
        std::cout << "This will not print!\n";
    #endif

    #if 1 // if tells the preprocessor to check if the expression evaluates to true. If it does, the code between #if and #endif will be included. Otherwise, it will be excluded. In this case, the expression is 1, which is always true, so the code will always be included.
        std::cout << "This will print!\n";
    #endif

    

    return 0;
}