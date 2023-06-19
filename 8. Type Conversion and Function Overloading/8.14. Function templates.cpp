template <typename T> // this is the template parameter declaration, usually single capital letter
T max(T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}