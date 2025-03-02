#include <stdio.h>
#include "include/test_suite.h"
#include <dlfcn.h>
#include <string.h>

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
load_test_suite (test_unit *unit_data, char *lib_name)
{
    char function_name[256] = "";
    char line_number_name[256] = "";
    int unit_counter = 0;

    void *lib = dlopen(lib_name, RTLD_NOW | RTLD_NODELETE);

    if(lib)
    {
        while(true)
        {
            test_unit unit;
            sprintf(function_name, "test_%i", unit_counter);
            sprintf(line_number_name, "ln_test_%i", unit_counter);

            unit.function= (test_function*)dlsym(lib, function_name);
            int *line_number = (int*)dlsym(lib, line_number_name);

            if (line_number != NULL)
            {
                unit.line_number = *line_number;
            }

            if (unit.function != NULL)
            {
                unit_data[unit_counter] = unit;
            }
            else
            {
                break;
            }

            ++unit_counter;
        } 
        dlclose(lib);
    }
}

void
run_test_suite(test_unit *unit_data)
{
    for (int i = 0; i < 256; ++i)
    {
        if (unit_data[i].function == NULL)
        {
            break;
        }
        printf("%i: ", unit_data[i].line_number);
        unit_data[i].function();
    }
}

int
main(int argc, char **argv)
{
    char path[256] = "";
    
    test_unit units[256] = {};
    int test_index = 0;

    if(argc >= 2)
    {
        load_test_suite(units, argv[1]);
    }

    run_test_suite(units);

    return(0);
}
