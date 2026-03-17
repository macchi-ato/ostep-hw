// Q: How can two child processes communicate using a pipe?
// A: One child writes to the pipe, the other reads from it, using dup2 to redirect stdio.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fildes[2];
    pipe(fildes);

    // Child process 1: writes to pipe via stdout
    if (fork() == 0) {
        close(fildes[0]);                           // child 1 doesn't read from pipe
        dup2(fildes[1], STDOUT_FILENO);             // redirect stdout → pipe write end
        close(fildes[1]);                           // no longer need the original fd
        printf("Hello from child process 1!\n");
        exit(0);
    }

    // Child process 2: reads from pipe via stdin
    if (fork() == 0) {
        close(fildes[1]);                   // child 2 doesn't write to pipe
        dup2(fildes[0], STDIN_FILENO);      // redirect stdin → pipe read end
        close(fildes[0]);                   // no longer need the original fd
        char buf[100];
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            printf("Child process 2 received: %s", buf);
        }
        exit(0);
    }

    // Parent: closes both ends (only children use the pipe)
    close(fildes[0]);
    close(fildes[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}