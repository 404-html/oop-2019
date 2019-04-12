#include <cstring>
#include <string>
#include <iostream>

/*
    Barebones string implementation. Only to be used during exams when std::string is forbidden and we don't have time to implement a better one
*/

class MyString
{
 public:
    MyString()
    {
        // Bad. Small allocation in default constructor
        m_str = new char[1];
        m_str[0] = '\0';
    }

    MyString(const char* in_str)
    {
        copy(in_str);
    }

    ~MyString()
    {
        del();
    }

    MyString& operator=(const MyString& other)  // No operator=(const char*) will make calls such as MyString x; x = "kappa"; very inefficient
    {
        // Bad. See Ex03
        if (this != &other)
        {
            del();
            copy(other.m_str);
        }

        return *this;
    }

    MyString(const MyString& other)
    {
        copy(other.m_str);
    }

    // If you need to match strings
    bool operator==(const MyString& other) const
    {
        int len = strlen(m_str) + 1;
        return strncmp(m_str, other.m_str, len) == 0;
    }

    bool operator!=(const MyString& other) const
    {
        return !(*this == other);
    }

    // If you need to order strings lexicographically
    bool operator<(const MyString& other) const
    {
        int len = strlen(m_str) + 1;
        return strncmp(m_str, other.m_str, len) < 0;
    }

    void print() const
    {
        std::cout << m_str << std::endl;
    }

    // If you need to output a string
    friend std::ostream& operator<<(std::ostream& out, const MyString& str)
    {
        return out << str.m_str;
    }

    // Fuck it, just give me the cstring
    const char* c_str() const
    {
        return m_str;
    }

 private:
    // No size and capacity => doesn't support concatenation well, and .size() will be very slow
    char* m_str = nullptr;

    void del()
    {
        delete [] m_str;
    }

    void copy(const char* in_str)
    {
        if (!in_str)
        {
            in_str = "";
        }
        int len = strlen(in_str) + 1;
        m_str = new char[len];
        strncpy(m_str, in_str, len);
    }
};
