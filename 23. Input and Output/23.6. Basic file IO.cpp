#include <fstream>
#include <iostream>

int main()
{   
    // Output file stream
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1\n";
    outf << "This is line 2\n";

    std::endl(std::cout); // flush output buffer
    outf.close();         // close file

    // Input file stream
    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }

    inf.close(); // close file


    // File mode
    // We'll pass the ios:app flag to tell the ofstream to append
    // rather than rewrite the file. We do not need to pass in std::ios::out
    // because ofstream defaults to std::ios::out
    std::ofstream outf2{ "Sample.txt", std::ios::app };

    // If we couldn't open the output file stream for writing
    if (!outf2)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    outf2 << "This is line 3\n";
    outf2 << "This is line 4\n";

    std::endl(std::cout); // flush output buffer
    outf2.close();        // close file


    // Fstream
    // We'll pass the ios:ate flag to open the file for writing
    // and move the read/write pointer to the end of the file
    std::fstream iofile{ "Sample.txt", std::ios::in | std::ios::out | std::ios::ate };

    // If we couldn't open the output file stream for reading and writing
    if (!iofile)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened!\n";
        return 1;
    }

    // We'll write two lines into this file
    iofile << "This is line 5\n";
    iofile << "This is line 6\n";

    // Seek back to the beginning of the file
    iofile.seekg(0);

    // While there's still stuff left to read
    while (iofile)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(iofile, strInput);
        std::cout << strInput << '\n';
    }

    iofile.close(); // close file

    return 0;
}