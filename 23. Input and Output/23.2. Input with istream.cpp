#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    // Extraction operator
    char buffer[10];
    std::cout << "Enter a string: ";
    std::cin >> std::setw(10) >> buffer;    // setw() is used to limit the number of characters to be read


    // White space (get())
    char ch;
    std::cout << "Enter a character: ";
    while (std::cin.get(ch) && ch != '\n')
        std::cout << ch;


    // getline()
    char strBuf[100];
    std::cin.getline(strBuf, 100);
    std::cout << strBuf << '\n';
    std::cout << std::cin.gcount() << " characters were read" << '\n';


    // getline() for strings
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    std::cout << str << '\n';


    // peek()
    std::cout << "Enter a string: ";
    while (std::cin.peek() != '\n') // peek() returns the next character in the input sequence without extracting it
        std::cout.put(std::cin.get());

    
    // ignore()
    std::cout << "Enter a string: ";
    std::cin.ignore(5); // ignore() extracts and discards characters from the input stream until and including the next delimiter
    while (std::cin.peek() != '\n')
        std::cout.put(std::cin.get());

    
    // putback()
    std::cout << "Enter a string: ";
    std::cin.putback('X'); // putback() inserts a character back into the input stream
    while (std::cin.peek() != '\n')
        std::cout.put(std::cin.get());
}