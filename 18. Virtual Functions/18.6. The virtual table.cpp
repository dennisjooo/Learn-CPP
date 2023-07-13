#include <iostream>

class Base
{
public:
    virtual void function1() { std::cout << "Base::function1()\n"; };
    virtual void function2() { std::cout << "Base::function2()\n"; };
};

class D1: public Base
{
public:
    void function1() override { std::cout << "D1::function1()\n"; };
};

class D2: public Base
{
public:
    void function2() override { std::cout << "D2::function2()\n"; };
};


int main()
{   
    /*
    The idea of the virtual table (VTable) is that each class with virtual functions has a virtual table that contains pointers to each virtual function. So it looks something like this:
    Base vtable: [Base::function1(), Base::function2()]
    D1 vtable:   [D1::function1(), Base::function2()]
    D2 vtable:   [Base::function1(), D2::function2()]

    What it does is it assigns the right function if the function is virtual, and if it's not virtual, it just calls the function directly.
    */
    
    // Create a D1 object and call the right function1() --> D1::function1()
    D1 d1 {};
    Base* dPtr = &d1;
    dPtr->function1();


    // Create a Base object, since the VTable for Base has Base::function1() and Base::function2(), it will call Base::function1()
    Base b {};
    Base* bPtr = &b;
    bPtr->function1();

    return 0;
}