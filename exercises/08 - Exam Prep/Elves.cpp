#include <iostream>
#include <cassert>
#include "MyString.h"

class Elf
{
 public:
    Elf(const MyString& fn = "", const MyString& ln = "", unsigned _age = 0, unsigned _power = 1)
    {
        setFirstName(fn);
        setLastName(ln);
        setAge(_age);
        setPower(_power);
    }

    void setFirstName(const MyString& fn)
    {
        firstName = fn;
    }

    void setLastName(const MyString& ln)
    {
        lastName = ln;
    }

    void setAge(unsigned _age)
    {
        assert(_age <= 300);
        age = _age;
    }

    void setPower(unsigned _power)
    {
        assert(power >= 1 && power <= 15);
        power = _power;
    }

    MyString getFirstName() const
    {
        return firstName;
    }

    MyString getLastName() const
    {
        return lastName;
    }

    unsigned getAge() const
    {
        return age;
    }

    unsigned getPower() const
    {
        return power;
    }

    void print() const
    {
        firstName.print();
        lastName.print();
        std::cout << age << " " << power << std::endl;
    }

    bool operator<(const Elf& rhs) const
    {
        if (firstName < rhs.firstName) return true;
        if (lastName < rhs.lastName) return true;
        if (age < rhs.age) return true;
        return power < rhs.power;
    }

    bool operator==(const Elf& rhs) const
    {
        return firstName == rhs.firstName &&
               lastName == rhs.lastName &&
               age == rhs.age &&
               power == rhs.power;
    }

 private:
    MyString firstName = "";
    MyString lastName = "";
    unsigned age = 0;
    unsigned power = 1;	
};

class ElfTeam
{
 public:
    ElfTeam(const MyString& tm = ""):
        teamName(tm)
    {}

    ~ElfTeam()
    {
        del();
    }

    ElfTeam(const ElfTeam& other)
    {
        copy(other);
    }

    ElfTeam& operator=(const ElfTeam& other)
    {
        if (this != &other)
        {
            del();
            copy(other);
        }

        return *this;
    }

    bool operator <(const ElfTeam& rhs) const
    {
        return getPowerLevel() < rhs.getPowerLevel();
    }

    ElfTeam& operator+=(const Elf& elf)
    {
        if (size == capacity)
        {
            resize();
        }

        data[size++] = elf;

        return *this;
    }

    void print() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i].print();
            std::cout << "--------\n";
        }
    }

    void sort()
    {
        for (size_t i = 0; i < size - 1; ++i)
        {
            for (size_t j = i + 1; j < size; ++j)
            {
                if (data[j] < data[i])
                {
                    std::swap(data[i], data[j]);
                }
            }
        }
    }

    ElfTeam operator+(const ElfTeam& rhs) const
    {
        ElfTeam result = *this;

        for (size_t i = 0; i < rhs.size; ++i)
        {
            if (!contains(rhs.data[i]))
            {
                result += rhs.data[i];
            }
        }

        return result;
    }

    ElfTeam& operator-=(const Elf& elf)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] == elf)
            {
               for (size_t j = i; j < size - 1; ++j)
               {
                   data[j] = data[j+1];
               }
               size--;
               return *this; 
            }
        }
        return *this;
    }

 private:
    MyString teamName = "";
    Elf* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void del()
    {
        delete [] data;
    }

    void copy(const ElfTeam& other)
    {
        size = other.size;
        capacity = other.capacity;
        teamName = other.teamName;
        data = new Elf[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    void resize()
    {
        capacity  = capacity ? 2 * capacity : 1;
        Elf* tmp = data;
        data = new Elf[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = tmp[i];
        }

        delete [] tmp;
    }

    double getPowerLevel() const
    {
        unsigned power = 0;
        unsigned age = 0;

        for (size_t i = 0; i < size; ++i)
        {
            power += data[i].getPower();
            age += data[i].getAge();
        }

        return static_cast<double>(power) / age;
    }

    bool contains(const Elf& elf) const
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] == elf)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Elf a{"Pe6o", "Pe6ov", 12, 15};
    Elf b{"Legolas", "Sme6o", 300, 3};
    Elf c{"Fiki", "Azis", 24, 15};

    ElfTeam team1;
    team1+=a;
    team1+=b;

    ElfTeam team2;
    team2+=a;
    team2+=c;

    ElfTeam team3 = team1 + team2;
    team3.print();
    std::cout << std::endl << std::endl;
    team3-=b;
    team3.print();



    MyString x;
    x = "kappa";
    std::cout << x << std::endl;

    return 0;
}