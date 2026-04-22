#include <stdlib.h>
#include <stdio.h>

int main() {
    // Running program normally
        // Silent bug
        // After running free(), the memory is returned but pointer still holds address
        // Returns garbage values

    // Valgrind error
        // Invalid read of size 4
        // Valgrind flags any access after free() as an invalid read
    int *arr = malloc(10 * sizeof(int));
    free(arr);

    // Pass "funny" valure to free: free(arr + 5)
        // free(): invalid pointer
        // arr + 5 is valid
        // However, free() expects the exact pointer that malloc returned

    printf("%d\n", arr[2]);

    return 0;
}