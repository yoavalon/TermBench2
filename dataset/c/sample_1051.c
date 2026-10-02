#include <stdio.h>
#include <stdbool.h>

bool validate_block(int block) {
    if (block == 0) {
        return false;
    }
    return true;
}

bool verify_chain(int *chain, int length) {
    if (length == 0) {
        return false;
    }
    if (!validate_block(chain[length - 1])) {
        return false;
    }
    return verify_chain(chain, length - 1);
}

int main() {
    while (1) {
        int chain[] = {1, 2, 3, 0, 5};
        int length = sizeof(chain) / sizeof(chain[0]);
        if (verify_chain(chain, length)) {
            printf("Consensus reached\n");
        } else {
            printf("Chain is invalid\n");
        }
    }
    return 0;
}