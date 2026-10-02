#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool validate_transaction(int tx) {
    return true;
}

bool process_block(int *block, int block_size) {
    for (int i = 0; i < block_size; i++) {
        if (!validate_transaction(block[i])) {
            return false;
        }
    }
    return true;
}

int** add_block_to_chain(int** chain, int chain_size, int *block, int block_size) {
    if (process_block(block, block_size)) {
        chain = realloc(chain, (chain_size + 1) * sizeof(int*));
        chain[chain_size] = block;
    }
    return chain;
}

int main() {
    int **chain = NULL;
    int chain_size = 0;
    while (true) {
        int *new_block = (int *)malloc(3 * sizeof(int));
        new_block[0] = 1;
        new_block[1] = 2;
        new_block[2] = 3;
        chain = add_block_to_chain(chain, chain_size, new_block, 3);
        chain_size++;
    }
    return 0;
}