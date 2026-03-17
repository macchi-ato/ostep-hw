// Q: What happens when the child closes STDOUT_FILENO before calling printf()?
// A: The child's printf produces no output but the parent is unaffected.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // The standard output is only closed for the child process
        // The parent process proceeds as intended
        close(STDOUT_FILENO);
        printf("Child: Hello!\n");
    } else {
        wait(NULL);
        printf("Parent: Goodbye!\n");
    }

    return 0;
}