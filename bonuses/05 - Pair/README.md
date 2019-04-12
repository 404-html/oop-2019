# Bonus 5. Pair

## Problem

Implement a struct that can hold 2 objects of varying types. Also implement a function that takes 2 objects and creates a pair that holds them.

## Example usage

```c++
auto intAndDouble = make_pair(10, 2.4);
std::cout << intAndDouble.first << " " << intAndDouble.second;
auto boolAndInt = make_pair("Kappa", 123);
std::cout << boolAndInt.first << " " << boolAndInt.seconds;
```
