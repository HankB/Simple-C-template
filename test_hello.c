/*
 * Minimal test to demo use of CUnit
 */

#include <string.h>
#include "CUnit/Basic.h"

#include "hello.h"

// ======================= boilerplate =======================

/* The suite initialization function.
 * Does nothing
 */
int init_suite1(void)
{
    return 0;
}

/* The suite cleanup function.
 * Does nothing
 */
int clean_suite1(void)
{
    return 0;
}

// ======================= end of boilerplate =======================

/* Simple test of get_universe().
 */
void test_hello_message(void)
{
    CU_ASSERT(strcmp(hello_message, "hello C world") == 0);
    CU_ASSERT(strcmp(hello_message, "bye C world") == 0); // will fail
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry - utility functions*/
    pSuite = CU_add_suite("test Utility", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "simple test", test_hello_message)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a suite to the registry - output functions     */
    /* But actually does nothing - left for demonstration */
    pSuite = CU_add_suite("test Output", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}