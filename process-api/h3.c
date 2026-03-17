// Q: Is it possible to ensure the child prints before the parent without using wait()?
// A: Yes, using signals (SIGUSR1) and pause() to synchronize.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


// Signal handler unblocks pause()
void handler(int sig) {
    (void)sig;
}

int main() {
    signal(SIGUSR1, handler);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Child runs first
        printf("Child: Hello!\n");
        // Tell parent we're done
        kill(getppid(), SIGUSR1);
    } else {
        // Parent waits for signal from child
        pause();
        printf("Parent: Goodbye!\n");
    }

    return 0;
}