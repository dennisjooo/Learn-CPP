#include <iostream>
#include <cstdint> // for fixed width integers

class Average
{
    private:
        std::int32_t m_sum { 0 };
        std::int8_t m_count { 0 };
    public:
        Average()
        {
        }
        friend std::ostream& operator<<(std::ostream& out, const Average& average);

        Average& operator+=(int num)
        {
            m_sum += num;
            ++m_count;
            return *this;
        }
};

std::ostream& operator<<(std::ostream& out, const Average& average)
{
    out << static_cast<double>(average.m_sum) / average.m_count;
    return out;
}

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n';

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}