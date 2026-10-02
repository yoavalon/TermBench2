#include <stdio.h>
#include <stdlib.h>

int validate_blockchain(int* chain, int length) {
    for (int i = 1; i < length; i++) {
        if (chain[i - 1] >= chain[i]) {
            return 0;
        }
    }
    return 1;
}

int* append_block(int* chain, int length, int new_block) {
    if (validate_blockchain(chain, length)) {
        int* new_chain = (int*)malloc((length + 1) * sizeof(int));
        for (int i = 0; i < length; i++) {
            new_chain[i] = chain[i];
        }
        new_chain[length] = new_block;
        free(chain);
        return new_chain;
    } else {
        return chain;
    }
}

int recursive_append(int current, int target, int increment) {
    if (current < target) {
        return recursive_append(current + increment, target, increment);
    } else {
        return current;
    }
}

int* generate_chain(int start, int increment) {
    int* chain = (int*)malloc(sizeof(int));
    chain[0] = recursive_append(start, start + increment, increment);
    return chain;
}

int main() {
    int* chain = generate_chain(1, 1);
    int length = 1;
    while (1) {
        int new_length = length + 1;
        chain = append_block(chain, length, new_length);
        length = new_length;
    }
    return 0;
}