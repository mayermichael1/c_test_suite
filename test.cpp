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

struct test_unit
{
    int line_number;
    test_function *function;
};

int
main(void)
{
    void *lib = dlopen("./example.so", RTLD_NOW | RTLD_NODELETE);
    char function_name[256] = "";
    char line_number_name[256] = "";
    test_unit units[256] = {};

    int test_index = 0;
    if(lib)
    {
        while(true)
        {
            test_unit unit;
            sprintf(function_name, "test_%i", test_index);
            sprintf(line_number_name, "ln_test_%i", test_index);

            unit.function= (test_function*)dlsym(lib, function_name);
            int *line_number = (int*)dlsym(lib, line_number_name);

            if (line_number != NULL)
            {
                unit.line_number = *line_number;
            }

            if (unit.function != NULL)
            {
                units[test_index] = unit;
            }
            else
            {
                break;
            }

            ++test_index;
        } 
        dlclose(lib);
    }


    for (int i = 0; i < test_index; ++i)
    {
        printf("%i: ", units[i].line_number);
        units[i].function();
    }

    printf("Hello World\n");
    return(0);
}
