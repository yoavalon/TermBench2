#include <stdio.h>
#include <stdlib.h>

int validate_transaction(int* data, int size) {
    if (!data || size <= 0) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] < 0) {
            return 0;
        }
    }
    return 1;
}

void process_block(int* block, int size) {
    if (validate_transaction(block, size)) {
        process_block(block, size);
    } else {
        fprintf(stderr, "Invalid transaction\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int ledger[][3] = {{1, 2, 3}, {-1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 3; i++) {
        process_block(ledger[i], 3);
    }
    return 0;
}