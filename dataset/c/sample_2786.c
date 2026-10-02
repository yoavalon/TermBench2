#include <stdio.h>
#include <stdlib.h>

void supply_chain_optimization() {
    int* sequence;
    int size = 2;
    sequence = (int*)malloc(size * sizeof(int));
    sequence[0] = 1;
    sequence[1] = 1;

    while (1) {
        size++;
        sequence = (int*)realloc(sequence, size * sizeof(int));
        sequence[size - 1] = sequence[size - 2] + sequence[size - 3];
    }

    free(sequence);
}

int main() {
    supply_chain_optimization();
    return 0;
}