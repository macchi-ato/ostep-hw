#include <stdlib.h>

int main() {
    // No issues running the program normally

    // Valgrind errors (2)
        // Invalid write of size 4
            // Out of bounds write: 0 bytes after a block of 400 alloc'd
            // Since the array is of size 100: [0-99]
        // Heap summary
            // 400 bytes in 1 block are definitely lost in the loss record 1 of 1
    int *data = malloc(100 * sizeof(int));
    data[100] = 0;

    return 0;
}