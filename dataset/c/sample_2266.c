#include <stdio.h>
#include <stdlib.h>

double* process_transaction(double* block, int* size, double transaction) {
    block = realloc(block, (*size + 1) * sizeof(double));
    block[*size] = transaction;
    (*size)++;
    return block;
}

double calculate_consensus(double* block, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += block[i];
    }
    return total / size;
}

int main() {
    double* block = NULL;
    int size = 0;
    while (1) {
        double transaction = 0.1;
        block = process_transaction(block, &size, transaction);
        double consensus = calculate_consensus(block, size);
        printf("%f\n", consensus);
    }
    return 0;
}