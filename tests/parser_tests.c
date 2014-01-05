#include "minunit.h"

char *test_parse1()
{
    return parse();
}


char *all_tests() {
    mu_suite_start();

    mu_run_test(test_pase1);

    return NULL;
}

RUN_TESTS(all_tests);
