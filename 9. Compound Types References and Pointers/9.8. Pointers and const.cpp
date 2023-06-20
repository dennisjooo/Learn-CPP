int main()
{   
    // Pointers and const
    const int x{ 5 };
    const int* ptr { &x }; // okay: ptr is pointing to a "const int"

    const int y{ 6 };
    ptr = &y; // okay: ptr now points at const int y


    // Const pointer to non-const data
    int x2{ 5 };
    const int* ptr2 { &x2 }; // ptr points to a "const int"

    x2 = 6; // the value stored at address ptr can be changed


    // Pointer const 
    int* const ptr3 { &x2 }; // ptr is const; the int that ptr points to is not const you cannot change the address stored in ptr

    *ptr3 = 7; // okay: changes value of x to 7


    // Const pointer const
    const int* const ptr4 { &x2 }; // ptr is const; the int that ptr points to is const. Pretty much immutable


    return 0;
}