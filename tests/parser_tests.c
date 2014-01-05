#include "minunit.h"
#include <parser.h>

char *test_parse1()
{
    ep3parse(stdin);
    return NULL;
}


char *all_tests() {
    mu_suite_start();

    mu_run_test(test_parse1);

    return NULL;
}

RUN_TESTS(all_tests);
