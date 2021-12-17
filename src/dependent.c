/* dependent.c
 * Tests libratings.so as a dependent library.
 *****************************************************/
 
#include <stdio.h>
#include <string.h>
#include "ratings.h"
 
#define PASSFAIL "Passed":"Failed"
#define UNTST "Untested"
 
int main(int argc, char **argv) {
    printf("[start_test]\n");
 
    // Setup.
    add_rating(NULL);
    add_rating("");
    add_rating("*");
    add_rating("**");
    add_rating("***");
    add_rating("*****");
    add_rating("*****");
 
    // ratings.
    printf("[%s] ratings(): %s\n",
        __FILE__, (ratings() == 6? PASSFAIL));
 
    // mean_rating.
    printf("[%s] mean_rating(): %s\n",
        __FILE__, (strcmp(mean_rating(), "**") == 0)? PASSFAIL);
 
    // clearRatings.
    clear_ratings();
    printf("[%s] clearRatings(): %s\n",
        __FILE__, (ratings() == 0? PASSFAIL));
 
    printf("[end_test]\n");
    return 0;
}
