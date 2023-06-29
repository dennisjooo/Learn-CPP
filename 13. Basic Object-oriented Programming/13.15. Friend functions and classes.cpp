#include <iostream>

class Accumulator; // Forward declaration (prototype)

class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}


// Friend classes
class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    {
    }

    void displayItem(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
};

class Storage
{
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
       : m_nValue { nValue }, m_dValue { dValue }
    {
    }

    // Make the Display class a friend of Storage
    friend class Display;


    // Friend member functions
    // Make the Display::displayItem() function a friend of the Storage class
    friend void Display::displayItem(const Storage& storage);
};



int main()
{   
    // Friend functions
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0


    // Friend classes
    Storage storage{5, 6.7};
    Display display{false};

    display.displayItem(storage);
    return 0;
}