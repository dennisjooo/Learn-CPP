#include <string_view>
#include <iostream>

class A
{
public:
	virtual std::string_view getName1(int x) { return "A"; }
	virtual std::string_view getName2(int x) { return "A"; }
	virtual std::string_view getName3(int x) { return "A"; }

    virtual std::string_view getName4(int x) final { return "A"; } // Final specifier prevents overriding in derived classes
};

class B : public A
{
public:
	// std::string_view getName1(short int x) override { return "B"; } // compile error, function is not an override
	// std::string_view getName2(int x) const override { return "B"; } // compile error, function is not an override
	std::string_view getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

};

class C final : public B // Final specifier to the class prevents further derivation
{
public:
    std::string_view getName3(int x) override { return "C"; } // okay, function is an override of B::getName3(int)

    // std::string_view getName4(int x) override { return "C"; } // compile error, function is final in A
};


// Covariant return types
class Base
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};


int main()
{   
	Derived d{};
	Base* b{ &d };
	d.getThis()->printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
	b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType
    return 0;
}