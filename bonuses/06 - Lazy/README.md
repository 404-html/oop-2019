# Bonus 5. Lazy

## Problem

Implement a function make_lazy that takes a function of 0 parameters and returns an object that will lazily store the value (it will only calculate it when it is needed and never recalculate it)

## Black Magic
```
// You can use this to get the return type of the function
// ??? is the type of the function
using result_type = typename std::__invoke_result<???>::type;
```

## Example usage

```c++
auto x = make_lazy([](){ std::cout << "...Calculating" << std::endl; return 10 * 10; });  // Imagine this being an actually hard computation :D
// x "stores" the value but doesn't actually calculate it yet
std::cout << "First Call assingment / calculates the value:" << std::endl;
int z = x;  // We need the value now, so we calculate it
std::cout << z << std::endl;
std::cout << "Second Call in function / doesn't recalculate" << std::endl;
[&](int num){ std::cout << num << std::endl; }(x);  // We need the value again, but we don't have to recalculate it
std::cout << "3rd call explicit cast / doesn't recalculcate" << std::endl;
std::cout << static_cast<int>(x) << std::endl;  // We need the value again, but we don't have to recalculate it
```
