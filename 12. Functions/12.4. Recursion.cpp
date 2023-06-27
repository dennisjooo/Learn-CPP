#include <iostream>
#include <vector>

void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count-1);

    std::cout << "pop " << count << '\n';
}

// return the sum of all the integers between 1 (inclusive) and sumto (inclusive)
// returns 0 for negative numbers
int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0; // base case (termination condition) when user passed in an unexpected argument (0 or negative)
    if (sumto == 1)
        return 1; // normal base case (termination condition)

    return sumTo(sumto - 1) + sumto; // recursive function call
}

int fibonacci(int count)
{
    if (count == 0)
        return 0; // base case (termination condition)
    if (count == 1)
        return 1; // base case (termination condition)
    return fibonacci(count-1) + fibonacci(count-2);
}

// h/t to potterman28wxcv for a variant of this code
int fibonacci_mem(int count)
{
	// We'll use a static std::vector to cache calculated results
	static std::vector results{ 0, 1 };

	// If we've already seen this count, then use the cache'd result
	if (count < static_cast<int>(std::size(results)))
		return results[count];

	// Otherwise calculate the new result and add it
	results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
	return results[count];
}

int main()
{   
    // Count down from 5 to 1
    countDown(5);

    // Sum all numbers from 1 to 5
    std::cout << sumTo(5) << '\n'; // 15

    // Print the first 13 numbers of the fibonacci sequence
    for (int count{ 0 }; count < 13; ++count)
        std::cout << fibonacci(count) << ' ';

    std::cout << '\n';

    // Print the first 13 numbers of the fibonacci sequence using memoization
    for (int count{ 0 }; count < 13; ++count)
        std::cout << fibonacci_mem(count) << ' ';
    return 0;
}