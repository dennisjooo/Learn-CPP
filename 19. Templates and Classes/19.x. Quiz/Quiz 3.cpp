#include <iostream>
#include <string>

template < typename T >

class StringValuePair
{
    private:
        std::string m_first;
        T m_second;
    public:
        StringValuePair(std::string first, T second)
            : m_first{ first }, m_second{ second }
        {
        }

        std::string first() const { return m_first; }
        T second() const { return m_second; }
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}