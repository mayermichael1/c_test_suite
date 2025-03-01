#include <stdio.h>
#include "include/test_suite.h"

//TODO: save the line numbers for specific test functions
//TODO: be able to call all test functions at once for testing


UNIT()
{
    printf("test\n");
    return(true);
}

int
main(void)
{
    test_0();
    printf("Hello World\n");
    return(0);
}
