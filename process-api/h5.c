// Q: What happens when wait() is called in the child process?
// A: It returns -1 because the child has no children of its own to wait for.

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
        printf("Child wait returned: %d\n", wait(NULL));    // Nothing happens since wait only waits for the calling process's own child
                                                            // since the child process hasn't forked anything any children of its own
                                                            // there is nothing to wait for so it returns -1
        int pid = getpid();
        printf("Child %d: Hello!\n", pid);
    } else {
        printf("wait for child: %d\n", wait(NULL));   // Returns the pid of the child process that ended
        printf("Parent: Goodbye!\n");
    }

    return 0;
}