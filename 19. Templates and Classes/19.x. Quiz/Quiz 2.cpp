#include <iostream>

template< typename T, typename S>

class Pair
{
    private:
        T m_first;
        S m_second;
    public:
        Pair(T first, S second)
            : m_first{ first }, m_second{ second }
        {
        }

        T first() const { return m_first; }
        S second() const { return m_second; }
};

int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}