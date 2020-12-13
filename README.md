# Eval Parser

Cpp library built from scratch that parse and evaluates a math expresion from a string.

## Sintax:

    Eval("math expresion as a string", list of numbers that the variable will accept)

Eg: Lets supose we want to evaluate `x` with the values `[1, 3, 4]` in the expresion `x + 3`, to do that we just
type the following.

    Eval("x + 3", [1, 3, 4]);

## Return type:

This function will return a list of the same length as the values that the variable wants to be
evaluated.

    Eval("x+3", [1, 3, 4]) ===> [1+3,3+3,4+3] ===> [4,6,7]

- Tests

In this project I used googletest library so, in order to use the same `test.cpp` file
you must integrate the project with the gtest_main lib.

For more info visit [googletest github page](https://github.com/google/googletest).
