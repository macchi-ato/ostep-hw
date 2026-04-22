#include <stdlib.h>
#include <stdio.h>

int main() {
    // GDB error
        // Found no error since there was no program crash
        // Forgetting free() is a silent bug
    
    // Valgrind error
        // Caught error using the --leak-check=yes flag
        // Tracks every heap allocation and checks if it was freed
        
    // Head usage: 1 allocs, 0 frees, 8 Bytes allocated
    int *n = malloc(2 * sizeof(int));

    return 0;
}