#include <stdio.h>
#include "include/test_suite.h"
#include <dlfcn.h>

//TODO: save the line numbers for specific test functions
//TODO: be able to call all test functions at once for testing


UNIT()
{
    printf("test\n");
    return(true);
}

TEST_FUNCTION(stub)
{
    printf("this is a stub function\n");
    __builtin_trap();
    return false;
}

int
main(void)
{
    test_function *func = NULL;
    void *lib = dlopen("./example.so", RTLD_NOW);
    if(lib)
    {
        func = (test_function*)dlsym(lib, "test_1");
        if (!func)
        {
            func = stub;
        }
    }

    func();

    printf("Hello World\n");
    return(0);
}
