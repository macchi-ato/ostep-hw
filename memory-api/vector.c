#include <stdlib.h>
#include <stdio.h>

/*
    *
    * Valgrind summary
    *   0 erros from 0 contexts
    * 
    * How does the vector perfom compared to a linked list?
    *   Inefficient due to frequent copies
    * 
    *   A liked list avoids copies but loses random access and cache efficiency
    * 
    *   Neither is ideal
    *   
    *   Doubling is a better solution
    * 
*/

int size = 0;
int capacity = 2;

void push(int **vec, int value) {
    if (size == capacity) {
        capacity++;
        *vec = realloc(*vec, capacity * sizeof(int));
    }
    (*vec)[size++] = value;
}

int main() {
    int *vec = malloc(capacity * sizeof(int));

    push(&vec, 10);
    push(&vec, 20);

    // Triggers realloc
        // Capacity was 2
        // Now grows to 3
    push(&vec, 30);

    for (int i = 0; i < size; i++) {
        printf("%d\n", vec[i]);
    }

    free(vec);
    return 0;
}