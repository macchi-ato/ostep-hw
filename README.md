## Chapters

### Process API (Chapter 5)

| File | Question |
|------|----------|
| h1.c | Do parent and child share a variable after `fork()`? |
| h2.c | Can both processes access the same open file descriptor? |
| h3.c | Can the child print before the parent without `wait()`? |
| h4.c | What are the different `exec()` variants? |
| h5.c | What happens when the child calls `wait()`? |
| h6.c | What's the difference between `wait()` and `waitpid()`? |
| h7.c | What happens when the child closes stdout? |
| h8.c | How do two child processes communicate via a pipe? |

---

### Address Spaces (Chapter 13)

Created `memory-user.c`, a program that allocates a specified number of megabytes and continuously streams through the array, touching each entry for a given duration. Used alongside tools like `free` and `pmap` to observe memory usage.

---

### Memory API (Chapter 14)

| File | Question |
|------|----------|
| null.c | What happens when you create a NULL pointer and dereference it? |
| malloc.c | What does valgrind report when allocated memory is never freed? |
| data.c | What happens when you write to `data[100]` in a 100 element array? |
| free.c | What happens when you read from memory after freeing it? |
| vector.c | How do you implement a dynamic array using `realloc()`? |
