#include <cstdlib> // for std::exit(), std::atexit(), std::abort()
#include <iostream>

void cleanup()
{
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
}

int main()
{   
    // Try not to use halts in your code. They are generally considered bad practice.

    // register cleanup() to be called automatically when std::exit() is called
    std::atexit(cleanup); // note: we use cleanup rather than cleanup() since we're not making a function call to cleanup() right now
    

    //std::abort(); // terminate program with abnormal program termination, no cleanup is performed

    std::cout << 1 << '\n';

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
}