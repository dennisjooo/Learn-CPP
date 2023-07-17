#include <iostream>
#include <memory> // for std::unique_ptr
#include <utility> // for std::move

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
    
    friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource";
		return out;
	}
};


// Returning a unique_ptr from a function (possible but avoid)
std::unique_ptr<Resource> createResource()
{
    std::unique_ptr<Resource> res{ new Resource{} };
    return res; // this return value will invoke the move constructor
}

// Passing a unique_ptr to a function
void echoResource(std::unique_ptr<Resource> res)
{
    if (res)
        std::cout << *res << '\n';
}

void echoResource(Resource* res)
{
    if (res)
        std::cout << *res << '\n';
} 


int main()
{
	std::unique_ptr<Resource> res1{ new Resource{} }; // Resource created here
	std::unique_ptr<Resource> res2{}; // Start as nullptr

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

	// res2 = res1; // Won't compile: copy assignment is disabled
	res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
	std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");


    // Checking if unique_ptr is null before dereferencing (it returns a True or False)
    if (res2)
        std::cout << *res2 << '\n';
	return 0;


    // Creating a unique_ptr using std::make_unique (recommended)
    auto res3 { std::make_unique<Resource>() }; // Resource created here


    // Returning a unique_ptr from a function
    auto res4 { createResource() }; // Resource created here


    // Passing a unique_ptr to a function
    echoResource(std::move(res4)); // Resource moved here, use std::move since it needs move semantics
    auto ptr { std::make_unique<Resource>() };
    echoResource(ptr.get()); // Resource not moved, just a pointer is passed (preferred)
} 