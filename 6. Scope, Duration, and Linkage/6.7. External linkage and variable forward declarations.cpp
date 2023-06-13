// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

// // Forward declarations
// extern int g_y;                // forward declaration for non-constant global variable
// extern const int g_y;          // forward declaration for const global variable
// extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared