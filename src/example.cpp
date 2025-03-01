#include "../include/test_suite.h"
#include <stdio.h>

UNIT()
{
    printf("From inside example.cpp\n");
    return false;
}
