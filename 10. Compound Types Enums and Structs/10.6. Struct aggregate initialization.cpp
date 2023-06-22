struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee frank = { 1, 32, 60000.0 }; // copy-list initialization using braced list
    Employee robert ( 3, 45, 62500.0 );  // direct initialization using parenthesized list (C++20)
    Employee joe { 2, 28, 45000.0 };     // list initialization using braced list (preferred)


    // Designated initializers (C++20)
    Employee john { .id = 4, .wage = 50000.0 }; // only id and wage will be initialized, the initializer for age is ignored (need to be in order)


    // Assignment to initialized struct
    john = {.id = john.id, .age = 29, .wage = john.wage}; // only age will be changed

    john = {john.id, 29, john.wage}; // same as above, but without designated initializers

    return 0;
}