#ifndef TEST_SUITE
#define TEST_SUITE

#define TEST_FUNCTION(name) bool(name)(void)
typedef TEST_FUNCTION(test_function);

#define UNIT_COUNTED_(counter) \
    int ln_test_##counter = __LINE__ ; \
    extern "C" TEST_FUNCTION(test_##counter) 

#define UNIT_COUNTED(counter) UNIT_COUNTED_(counter)

#define UNIT() UNIT_COUNTED(__COUNTER__)

#endif
