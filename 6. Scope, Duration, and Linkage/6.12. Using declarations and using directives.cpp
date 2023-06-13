#include <iostream>

int main()
{
    using std::cout; // this using declaration tells the compiler that cout should resolve to std::cout
    cout << "Hello world!\n"; // so no std:: prefix is needed here!

    using namespace std; // this using directive tells the compiler to import all names from namespace std into the current namespace without qualification
    cout << "Hello world!\n"; // so no std:: prefix is needed here
    return 0;
        
    return 0;
} // the using declaration expires here