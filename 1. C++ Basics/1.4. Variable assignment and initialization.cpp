#include <iostream>

int main()
{  
   // Variable instantiation
   [[maybe_unused]] int x; // Define x as an integer variable
   [[maybe_unused]] double width; // Define width as a double variable

   [[maybe_unused]] int a, b; // Define multiple variables of the same type


   // Variable assignment
   x = 5; // Assign the value 5 to x
   width = 1.5; // Assign the value 1.5 to width
   x = 5 + 2; // Assign the value 7 to x

   
   // Variable initialization
   [[maybe_unused]] int d; // No initialization(default initialization)
   [[maybe_unused]] int dd = 5; // Initialize x to 5 (copy initialization)
   [[maybe_unused]] int ddd(5); // Initialize x to 5 (direct initialization)

   // List Initialization (Preferred)
   /* benefits over traditional initialization:
      1. It prevents narrowing conversions.
      2. It prevents inadvertent type conversions.
      3. It’s more consistent.
   */
   [[maybe_unused]] int xx { 5 }; // Initialize x to 5 (direct list initialization)
   [[maybe_unused]] int xxx = { 5 }; // Initialize x to 5 (copy list initialization)
   [[maybe_unused]] int xxxx {}; // Initialize x to 0 (value initialization)

   std::cout << xxxx << std::endl; // prints 0

   // Initialization of multiple variables
   [[maybe_unused]] int xa { 5 }, ya { 6 }; // Initialize x to 5 and y to 6
   [[maybe_unused]] int xb = 5, yb = 6; // Initialize x to 5 and y to 6 (copy initialization)
   [[maybe_unused]] int xc(5), yc(6); // Initialize x to 5 and y to 6 (direct initialization)
   [[maybe_unused]] int i {}, j {}; // Initialize i and j to 0 (value initialization)

   std::cout << xa << std::endl; // prints 5

   // Maybe Unused Variables
   [[maybe_unused]] double pi {3.14}; // The compiler will not warn about this unused variable, -Werror will bite you in the ass if not

   return 0;
}