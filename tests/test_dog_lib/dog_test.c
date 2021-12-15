#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>


/* A test case that does nothing and succeeds. */
static void test_intro_print(void **state) {
    (void) state; /* unused */
}
int main(void) {

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_intro_print),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
