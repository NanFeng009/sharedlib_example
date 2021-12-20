/** @file dog.c
 *  @brief A dog animal
 */


#include <stdio.h>

void dog(void) 
{
	FILE *out=fopen("name_of_file.txt","w");
	fputs("Hello File",out);
	fclose(out);
}
