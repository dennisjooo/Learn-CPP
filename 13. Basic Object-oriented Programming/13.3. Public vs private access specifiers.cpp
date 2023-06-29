#include <array>
#include <cassert>
#include <iostream>

class DateClass // members are private by default
{
	int m_month {}; // private by default, can only be accessed by other members
	int m_day {}; // private by default, can only be accessed by other members
	int m_year {}; // private by default, can only be accessed by other members

public:
	void setDate(int month, int day, int year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}

	void print()
	{
		std::cout << m_month << '/' << m_day << '/' << m_year;
	}

	// Note the addition of this function
	void copyFrom(const DateClass& d)
	{
		// Note that we can access the private members of d directly
		m_month = d.m_month;
		m_day = d.m_day;
		m_year = d.m_year;
	}
};

class Stack
{
private:
	// We use a std::array to store the elements
	using Array = std::array<int, 10>;
	// For convenience, add a type alias for the type of the indexes
	using Index = Array::size_type;

	Array m_array {}; // Here's where we're going to store our stack data
	Index m_next{ 0 }; // This will hold the index of the next free element on the stack

public:

	void reset()
	{
		m_next = 0;
        m_array = {};
	}

	bool push(int value)
	{
		// If the stack is already full, return false now
		if (m_next == m_array.size())
			return false;

		m_array[m_next++] = value; // set the next free element to the value, then increase m_next
		return true;
	}

	int pop()
	{
		// If there are no elements on the stack, assert out
		assert (m_next > 0 && "Can not pop empty stack");

		// m_next points to the next free element, so the last valid element is m_next -1.
		// what we want to do is something like this:
		// int val = m_array[m_next-1]; // get the last valid element
		// --m_next; // m_next is now one less since we just removed the top element
		// return val; // return the element
		// that can be condensed down into this:
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (Index i{ 0 }; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};


int main()
{
	DateClass date;
	date.setDate(10, 14, 2020); // okay, because setDate() is public

	DateClass copy {};
	copy.copyFrom(date); // okay, because copyFrom() is public
	copy.print();
	std::cout << '\n';



    // Stack
    Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.reset();
	stack.print();

	return 0;
}