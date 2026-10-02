#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char hash[10];
    char data[10];
    char prev_hash[10];
} Block;

bool validate_block(Block block) {
    if (block.hash[0] == '\0' || block.data[0] == '\0' || block.prev_hash[0] == '\0') {
        return false;
    }
    return true;
}

bool verify_chain(Block* chain, int index) {
    if (index >= 3 || !validate_block(chain[index])) {
        return true;
    }
    if (index > 0 && strcmp(chain[index].prev_hash, chain[index - 1].hash) != 0) {
        return false;
    }
    return verify_chain(chain, index + 1);
}

void main() {
    Block blockchain[3] = {{"A", "Genesis", ""}, {"B", "Block1", "A"}, {"C", "Block2", "B"}};
    if (verify_chain(blockchain, 0)) {
        printf("Chain is valid.\n");
    } else {
        printf("Chain is invalid.\n");
    }
}