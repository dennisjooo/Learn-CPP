#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

int main()
{   
    // Iterating over a vector
    std::vector<int> vect;
    for (int count=0; count < 6; ++count)
        vect.push_back(count);

    std::vector<int>::const_iterator itVector; // declare a read-only iterator
    itVector = vect.cbegin(); // assign itVector to the start of the vector
    while (itVector != vect.cend()) // while itVector hasn't reach the end
    {
        std::cout << *itVector << ' '; // print the value of the element itVector points to
        ++itVector; // and iterate to the next element
    }

    std::cout << '\n';


    // Iterating over a list
    std::list<int> li;
    for (int count=0; count < 6; ++count)
        li.push_back(count);

    std::list<int>::const_iterator itList; // declare an iterator
    itList = li.cbegin(); // assign itList to the start of the list
    while (itList != li.cend()) // while itList hasn't reach the end
    {
        std::cout << *itList << ' '; // print the value of the element itList points to
        ++itList; // and iterate to the next element
    }

    std::cout << '\n';


    // Iterating over a set
    std::set<int> myset;
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);

    std::set<int>::const_iterator itSet; // declare an iterator
    itSet = myset.cbegin(); // assign itSet to the start of the set
    while (itSet != myset.cend()) // while itSet hasn't reach the end
    {
        std::cout << *itSet << ' '; // print the value of the element itSet points to
        ++itSet; // and iterate to the next element
    }

    std::cout << '\n';


    // Iterating over a map
    std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));

	auto itMap{ mymap.cbegin() }; // declare a const iterator and assign to start of vector
	while (itMap != mymap.cend()) // while itMap hasn't reach the end
	{
		std::cout << itMap->first << '=' << itMap->second << ' '; // print the value of the element itMap points to
		++itMap; // and iterate to the next element
	}

	std::cout << '\n';
}