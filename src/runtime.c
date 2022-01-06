/* Runtime.c
 * Tests libratings.so 1.0 as a runtime-loaded library.
 ***********************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include "ratings.h"
 
#define PASSFAIL "Passed":"Failed"
#define UNTST "Untested"
 
int main(int argc, char **argv) {
	(void) argc, argv;
    printf("[start_test]\n");
 
    // Open the library.
    char *lib_name = "./libratings.so";
    void *lib_handle = dlopen(lib_name, RTLD_NOW);
    if (lib_handle) {
        printf("[%s] dlopen(\"%s\", RTLD_NOW): Successful\n", __FILE__, lib_name);
    }
    else {
        printf("[%s] Unable to open library: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }
 
    // Get the symbol addresses.
    void (*add_rating)(char*) = dlsym(lib_handle, "add_rating");
    if (add_rating) {
        printf("[%s] dlsym(lib_handle, \"add_rating\"): Successful\n", __FILE__);
    }
    else {
        printf("[%s] Unable to get symbol: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }
    char *(*mean_rating)(void) = dlsym(lib_handle, "mean_rating");
    if (mean_rating) {
        printf("[%s] dlsym(lib_handle, \"mean_rating\"): Successful\n", __FILE__);
    }
    else {
        printf("[%s] Unable to get symbol: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }
    void (*clear_ratings)(void) = dlsym(lib_handle, "clear_ratings");
    if (clear_ratings) {
        printf("[%s] dlsym(lib_handle, \"clear_ratings\"): Successful\n", __FILE__);
    }
    else {
        printf("[%s] Unable to get symbol: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }
    int (*ratings)(void) = dlsym(lib_handle, "ratings");
    if (ratings) {
        printf("[%s] dlsym(lib_handle, \"ratings\"): Successful\n", __FILE__);
    }
    else {
        printf("[%s] Unable to get symbol: %s\n",
            __FILE__, dlerror());
        exit(EXIT_FAILURE);
    }
 
    // Setup.
    add_rating(NULL);
    add_rating("");
    add_rating("*");
    add_rating("**");
    add_rating("***");
    add_rating("*****");
    add_rating("*****");
 
    // ratings.
    printf("[%s] ratings(): %s\n", __FILE__, (ratings() == 6? PASSFAIL));
 
    // mean_rating.
    printf("[%s] mean_rating(): %s\n", __FILE__, (strcmp(mean_rating(), "**") == 0)? PASSFAIL);
 
    // clear_ratings.
    clear_ratings();
    printf("[%s] clear_ratings(): %s\n", __FILE__, (ratings() == 0? PASSFAIL));
 
    // Close the library.
    if (dlclose(lib_handle) == 0) {
        printf("[%s] dlclose(lib_handle): Successful\n", __FILE__);
    }
    else {
        printf("[%s] Unable to open close: %s\n",
            __FILE__, dlerror());
    }
 
    printf("[end_test]\n");
    return 0;
}

/*
 * dynamic load code from 
 * https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/DynamicLibraries/000-Introduction/Introduction.html
 * also can refer
 * https://wwww.geeksforgeeks.org/function-pointer-in-c
 */
