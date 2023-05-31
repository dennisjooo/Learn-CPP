#include <iostream>

double getInitialHeight();
double currentHeight(int seconds, double height);
void printHeight(int seconds, double height);

int main()
{
    double height{ getInitialHeight() };

    int seconds{ 0 };

    while (height > 0.0) {
        height = currentHeight(seconds, height);
        printHeight(seconds, height);
        seconds++;
    }

    return 0;
}

double currentHeight(int seconds, double height)
{
    constexpr double gravity{ 9.8 };
    return height - (gravity * seconds * seconds) / 2;
}

double getInitialHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;
    return height;
}

void printHeight(int seconds, double height)
{
    if (height > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}