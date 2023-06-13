#include <iostream>

namespace foo // define a namespace named foo
{
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace goo // define a namespace named goo
{
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int doSomething(int x, int y) // this doSomething() belongs to the global namespace
{
    return x * y;
}

namespace foo::goo // nested namespace definition
{
    int add(int x, int y);
}

namespace v2
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace boo = v2; // namespace alias

    std::cout << foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace foo

    std::cout << goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace goo
    return 0;

    std::cout << ::doSomething(4, 3) << '\n'; // use the doSomething() that exists in the global namespace

    return 0;
}