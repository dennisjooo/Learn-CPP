#include <cassert> // for assert()
#include <cmath> // for std::sqrt
#include <iostream>

// static_asserts are checked at compile time. must be constant expressions
static_assert(sizeof(long) >= 4, "long must be 8 bytes");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
  assert(gravity > 0.0 && "Gravity not greater than zero"); // The object won't reach the ground unless there is positive gravity.

  if (initialHeight <= 0.0)
  {
    // The object is already on the ground. Or buried.
    return 0.0;
  }

  return std::sqrt((2.0 * initialHeight) / gravity);
}

int main()
{
  std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

  return 0;
}