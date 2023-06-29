#include <iostream>

class Something
{
private:
    int m_value[3]; // note: we changed the implementation of this class!

public:
    // We have to update any member functions to reflect the new implementation
    void setValue1(int value) { m_value[0] = value; } // setters 
    int getValue1() { return m_value[0]; } // getters
};

int main()
{
    // But our program still works just fine!
    Something something;
    something.setValue1(5);
    std::cout << something.getValue1() << '\n';
}