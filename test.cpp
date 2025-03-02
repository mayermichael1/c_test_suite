#include <stdio.h>
#include "include/test_suite.h"
#include <dlfcn.h>
#include <string.h>

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

void
extract_path (char *full_name)
{
    for (int i = strlen(full_name) - 1; i > 0; ++i)
    {
        if (full_name[i] == '/')
        {
            break;
        }
        full_name[i] = 0;
    }
}


int
main(int argc, char **argv)
{
    char function_name[256] = "";
    char line_number_name[256] = "";
    char path[256] = "";
    char *lib_name = "";
    
    test_unit units[256] = {};
    int test_index = 0;

    if(argc >= 2)
    {
        lib_name = argv[1];
    }

    void *lib = dlopen(lib_name, RTLD_NOW | RTLD_NODELETE);

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
