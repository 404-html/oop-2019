#include <iostream>
#include <cstring>

class Shallow
{
 private:
    char * name;
 public:
    // Ignore the warnings, this is a demonstration on what NOT to do
    explicit Shallow(char * _name): name(_name) {}
    ~Shallow()
    {
        // This crashes the program because we try to delete memory that does not belong to us
        delete [] name;
    }

    void print() const
    {
        std::cout << name << std::endl;
    }
};

class Deep
{
 public:
    explicit Deep(const char* _name)
    {
        // Deep now owns a copy instead of the same object
        name = new char[strlen(_name) + 1];
        strncpy(name, _name, strlen(_name) + 1);
    }
    ~Deep()
    {
        // this won't crash the program
        delete [] name;
    }

    void print() const
    {
        std::cout << name << std::endl;
    }
 private:
    char * name;
};

int main()
{
    char x[50] = "Pe6o";
    Shallow s(x);
    // This looks fine and prints pe6o
    s.print();

    // Change x
    strncpy(x, "Stamat", 7);

    // s was also changed because it shares resources with main
    s.print();

    char xx[50] = "Go6o";
    Deep d(xx);

    // Still looks fine
    d.print();

    strncpy(xx, "Stavri", 7);
    // d didn't change because it own a copy of the cstring
    d.print();

    // Crashes because s tries to delete something that it doesn't own
    return 0;
}
