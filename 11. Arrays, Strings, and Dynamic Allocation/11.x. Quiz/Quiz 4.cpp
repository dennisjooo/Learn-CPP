#include <iostream>
#include <cstring>


void printString(const char* cstr)
{
    while (*cstr != '\0')
    {
        std::cout << *cstr;
        ++cstr;
    }
}

int main()
{

    printString("Hello world!");

    return 0;
}