# Bonus 7. Unique Pointer

## Problem

Implement a class unique_ptr that wraps a pointer to the heap and deletes it when it exits the current scope. To make sure there is no double delete make sure that copying the unique_ptr atually nulls the value you were trying to copy
(e.g. after x = y; x now stores y's old pointer and y stores nullptr). To make that modify the copy constructor and operator= appropriately (this is not the ideal solution, we will talk about a better one later)

Also implement
* operator*
* operator->
* operator bool
* method get that returns the raw pointer
* method release that returns the raw pointers and nulls the unique_pr
* method reset that takes a pointer, frees the old one and replaces it with a new one

## Example usage

```c++
struct Test
{
    ~Test()
    {
        std::cout << "destructor" << std::endl;
    }

    void print() const
    {
        std::cout << "print" << std::endl;
    }
};

int main()
{
    unique_ptr<Test> x = new Test();
    auto z = x;
    unique_ptr<Test> y;
    y = z;
    y->print();
    (*y).print();
    return 0;
}

/* Output:
print
print
destructor
*/

// Notice that the destructor is only called once.
```
