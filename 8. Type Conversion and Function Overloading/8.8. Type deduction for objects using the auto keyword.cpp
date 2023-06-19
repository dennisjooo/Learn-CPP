#include <string>
#include <string_view>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    auto d{ 5.0 }; // 5.0 is a double literal, so d will be type double
    auto i{ 1 + 2 }; // 1 + 2 evaluates to an int, so i will be type int
    auto x { i }; // i is an int, so x will be type int too

    auto sum { add(5, 6) }; // add() returns an int, so sum's type will be deduced to int

    // Auto only works for assignments that have an initializer (i.e. something on the right hand side of the =)

    
    // Const 
    const int x { 5 };  // x has type const int
    auto y { x };       // y will be type int (const is dropped)

    const auto z { x }; // z will be type const int (const is reapplied)


    // Strings
    auto s { "Hello, world" }; // s will be type const char*, not std::string

    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
    return 0;
}