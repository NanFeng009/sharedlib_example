/* File: ratings.h
 * Interface to libratings.so 1.0.
 *************************************/
 
/* Adds 'rating' to the set.
 *      rating: Each character adds 1 to the numeric rating
 *              Example: "" = 0, "*" = 1, "**" = 2, "wer " = 4.
 */
void add_rating(char *rating);
 
/* Returns the number of ratings in the set.
 */
int ratings(void);
 
/* Returns the mean rating of the set.
 */
char *mean_rating(void);
 
/* Clears the set.
 */
void clear_ratings(void);

