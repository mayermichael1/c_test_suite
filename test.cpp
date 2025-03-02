#include "include/test_suite.h"

//TODO: re-route stdout to null when running unit test

int
main(int argc, char **argv)
{
    test_unit_list list = {};

    if(argc >= 2)
    {
        load_test_suite(&list, argv[1]);
    }

    run_test_suite(list);

    return(0);
}
