#include <cstring>
#include <string>
#include <iostream>

class MyString
{
 public:
    MyString()
    {
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

    MyString& operator=(const MyString& other)
    {
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

    bool operator==(const MyString& other) const
    {
        int len = strlen(m_str) + 1;
        return strncmp(m_str, other.m_str, len) == 0;
    }

    bool operator!=(const MyString& other) const
    {
        return !(*this == other);
    }

    bool operator<(const MyString& other) const
    {
        int len = strlen(m_str) + 1;
        return strncmp(m_str, other.m_str, len) < 0;
    }

    void print() const
    {
        std::cout << m_str << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& str)
    {
        return out << str.m_str;
    }

    const char* c_str() const
    {
        return m_str;
    }

 private:
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
