#include <iostream> // Input-Output library

int main(){

    // << is the insertion operator
    std::cout << "Hello world"; // Print the good ol'

    std::cout << 4; //Print 4

    std::cout << "Hello" << " world"; // Print Hello world but with 2 insertion operators

    std::cout << "Hello" << " world" << std::endl; // Print Hello world and a new line since std::endl is the end line manipulator, it also flushes the buffer

    std::cout << "Hello\nworld"; // Print Hello world but with a new line since \n is the new line character, this does not flush the buffer

    std::cout << "Enter a number: "; // Prompt the user for a number
    int x{}; // Define an integer variable x
    std::cin >> x; // Get the user input and store it in x, >> is the extraction operator

    std::cout << "You entered " << x << std::endl; // Print the user input

    return 0;
}