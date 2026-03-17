// Q: What is the difference between wait() and waitpid()?
// A: wait() waits for any child and waitpid() waits for a specific child by pid.

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
        int childPid = getpid();
        printf("Child %d: Hello!\n", childPid);
    } else {
        // wait() waits for any child
        // waitpid() waits for a specific children by pid
        printf("wait for child: %d\n", waitpid(rc, NULL, 0));
        printf("Parent: Goodbye!\n");
    }

    return 0;
}