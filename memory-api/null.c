#include <stdio.h>

int main() {
    int *ptr = NULL;

    // Output error
        // Segmentation fault
        // Can't read at address 0x0

    // GDB error
        // Program received signal SIGSEGV, Segmentation fault
        // Bad memory access address: 0x000055555555514d in main () at null.c:13

    // Valgrind error
        // Invalid read of size 4
        // at 0x400114D: main
        // Address 0x0 is not stack'd, malloc'd or (recently) free'd

        // Process terminating with default action of signal 11 (SIGSEGV): dumping core
        // Access not within mapped region at address 0x0
        // at 0x400114D: main
        // If you believe this happened as a result of a stack
        // overflow in your program's main thread (unlikely but
        // possible), you can try to increase the size of the
        // main thread stack using the --main-stacksize= flag.
        // The main thread stack size used in this run was 8388608.
  
        // HEAP SUMMARY:
        // in use at exit: 0 bytes in 0 blocks
        // total heap usage: 0 allocs, 0 frees, 0 bytes allocated
        // All heap blocks were freed -- no leaks are possible

        // ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
        // zsh: segmentation fault (core dumped)  valgrind --leak-check=yes ./null
    printf("%d\n", *ptr);

    return 0;
}