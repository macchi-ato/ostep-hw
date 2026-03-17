// Q: What happens when both parent and child modify the same variable after fork()?
// A: Each gets its own copy, changes in one don't affect the other.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 100;
    printf("Start of process: %d\n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 50;
        printf("Child: %d\n", x);
    } else {
        x = 200;
        printf("Parent: %d\n", x);
    }

    printf("End of process: %d\n", x);
    return 0;
}