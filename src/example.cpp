#include "../include/test_suite.h"
#include <stdio.h>

UNIT()
{
    printf("From inside example.cpp\n");
    return false;
}

UNIT()
{
    printf("This is test 1\n");
    return false;
}

UNIT()
{
    printf("This is test 2\n");
    return false;
}

UNIT()
{
    printf("This is test 3\n");
    return false;
}
