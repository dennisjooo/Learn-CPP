#include <iostream>
#include <vector>

class Something
{
private:
    static int s_value;
public:
    static int getValue() { return s_value; } // static member function, doesn't have the "this" pointer, only has access to static member variables
};

int Something::s_value{ 1 }; // initializer


class IDGenerator
{
private:
    static int s_nextID; // Here's the declaration for a static member

public:
     static int getNextID(); // Here's the declaration for a static function
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::s_nextID{ 1 };

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; }


class MyClass
{
public:
	static std::vector<char> s_mychars;

	class init_static // we're defining a nested class named init_static
	{
	public:
		init_static() // the init constructor will initialize our static variable
		{
			for (char ch{ 'a' }; ch <= 'z'; ++ch)
			{
				s_mychars.push_back(ch);
			}
		}
	} ;

private:
	static init_static s_initializer; // we'll use this static object to ensure the init_static constructor is called
};


// C++ doesn't have static constructors, so we have to initialize static class members outside of the class
std::vector<char> MyClass::s_mychars{}; // define our static member variable
MyClass::init_static MyClass::s_initializer{}; // define our static initializer, which will call the init_static constructor, which will initialize s_mychars


int main()
{
    std::cout << Something::getValue() << '\n';


    for (int count{ 0 }; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}