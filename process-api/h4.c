// Q: What are the different variants of exec() and how do they differ?
// A: v = vector args, l = list args, p = searches PATH, e = custom environment.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    // Suffix v: args are passed as a vector (argv[])
    if (fork() == 0) {
        printf("This is execv child:\n");
        char *myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = strdup("./figures");
        myargs[2] = NULL;
        execvp("ls", myargs);
    }
    wait(NULL);
    printf("\n");

    // Suffix l: args are passed as a list (arg0, arg1, ..., NULL)
    if (fork() == 0) {
        printf("This is execl child:\n");
        execl("/bin/ls", "ls", "./figures", NULL); 
    }
    wait(NULL);
    printf("\n");

    // Suffix p: searches PATH for the program (just provide "ls" instead of "/bin/ls")
    if (fork() == 0) {
        printf("This is execlp child:\n");
        execlp("ls", "ls", "./figures", NULL); 
    }
    wait(NULL);
    printf("\n");

    // Suffix e: you supply a custom environment via an envp[] array
    if (fork() == 0) {
        printf("This is execle child:\n");
        char *myenv[] = { "PATH=/bin", NULL };
        execle("/bin/ls", "ls", "./figures", NULL, myenv);
    }
    wait(NULL);
    printf("\n");

    printf("Parent process\n");

    return 0;
}