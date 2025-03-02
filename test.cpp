#include "include/test_suite.h"

//TODO: re-route stdout to null when running unit test

int
main(int argc, char **argv)
{
    char path[256] = "";
    
    test_unit_list list = {};
    int test_index = 0;

    if(argc >= 2)
    {
        load_test_suite(&list, argv[1]);
    }

    run_test_suite(list);

    return(0);
}
