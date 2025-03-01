#include <stdio.h>

#define TEST_FUNCTION(name) bool(name)(void)
typedef TEST_FUNCTION(test_function);

TEST_FUNCTION(test1)
{
    printf("test\n");
    return true;
}

int
main(void)
{
    test_function* func = test1;
    func();
    printf("Hello World\n");
    return 0;
}
