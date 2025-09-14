# C Test Suite

This is a simple unit test implementation for C and C++ programs.
This suite can easily be implemented in existing projects to test certain units
of code.

## Usage

The test binary itself is used to load created shared library files and test 
them. The best way to use this suite is to compile the test binary and the shared 
library in the current built system. 

If a Makefile is used for building the current implementation can be copied.

Example structure:

```
[project root]
- Makefile
- test/
    - testcode.c
- lib/
    - test.c
    - src/
        test_suite_implementation.cpp 
    - include/
        test_suite.h
```

When the Makefile is run with the test target it should be built and tested 
automatically.

## Test Code

