#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    *
    *   Memory borrower
    * 
    *   For testing programs like free and pmap
    * 
*/

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num of megabytes> <seconds>\n", argv[0]);
        return 1;
    }

    int num_of_mbytes = atoi(argv[1]);
    int seconds = atoi(argv[2]);
    size_t num_ints = (size_t)num_of_mbytes * 1024 * 1024 / sizeof(int);

    // Malloc uses a block of memory from the heap
    // since stack allocated arrays (ex. int arr[n]) are limited
    // it would overflow if the user request a lot of memory
    int  *arr = malloc(num_ints * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    time_t start = time(NULL);
    while (time(NULL) - start < seconds) {
        for (size_t i = 0; i < num_ints; i++) {
            arr[i] = 0; // Touch each entry
        }
        printf("streaming through array...\n");
    }

    free(arr);
    return 0;
}