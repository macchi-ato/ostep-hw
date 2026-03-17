// Q: Can both parent and child access the same open file descriptor after fork()?
// A: Yes, both can write to it and the output from both ends up in the file.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd = open("h2.txt", O_CREAT | O_WRONLY);
    if (fd < 0) {
        fprintf(stderr, "open failed\n");
        exit(1);
    }
    printf("fd = %d\n", fd);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child (pid:%d) writing to fd %d\n", getpid(), fd);
        const char *msg = "child wrote this\n";
        write(fd, msg, strlen(msg));
    } else {
        printf("parent (pid:%d) writing to fd %d\n", getpid(), fd);
        const char *msg = "parent wrote this\n";
        write(fd, msg, strlen(msg));
    }

    close(fd);
    return 0;
}