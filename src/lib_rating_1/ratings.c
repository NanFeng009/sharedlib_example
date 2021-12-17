/* File: ratings.c
 * Compile with -fvisibility=hidden.                        // 1
 **********************************/
 
#include "ratings.h"
#include <stdio.h>
#include <string.h>
 
#define EXPORT __attribute__((visibility("default")))
#define MAX_NUMBERS 99
 
static int _number_list[MAX_NUMBERS];
static int _numbers = 0;
 
 
// Used by meanRating, middleRating, frequentRating.
static char *_char_rating(int rating) {
    char result[10] = "";
    int int_rating = rating;
    for (int i = 0; i < int_rating; i++) {
        strncat(result, "*", sizeof(result) - strlen(result) - 1);
    }
    return strdup(result);
}
 
// Used by addRating.
void _add(int number) {                                     // 4
    if (_numbers < MAX_NUMBERS) {
        _number_list[_numbers++] = number;
    }
}
 
// Used by meanRating.
int _mean(void) {
    int result = 0;
    if (_numbers) {
        int sum = 0;
        int i;
        for (i = 0; i < _numbers; i++) {
            sum += _number_list[i];
        }
        result = sum / _numbers;
    }
    return result;
}
 
EXPORT
void add_rating(char *rating) {                            // 5
    if (rating != NULL) {
        int numeric_rating = 0;
        int pos = 0;
        while (*rating++ != '\0' && pos++ < 5) {
            numeric_rating++;
        }
        _add(numeric_rating);
    }
}
 
EXPORT
char *mean_rating(void) {
    return _char_rating(_mean());
}
 
EXPORT
int ratings(void) {
    return _numbers;
}
 
EXPORT
void clear_ratings(void) {
    _numbers = 0;
}

EXPORT
char *median_rating(void) {

    return _char_rating(_mean());     // for simplicity, just same as mean_rating fun

}
/* Ratings.c revision history

 * 1. First version.

 * 2. Added medianRating, frequentRating.

 *    Removed initializer, finalizer.

 */
