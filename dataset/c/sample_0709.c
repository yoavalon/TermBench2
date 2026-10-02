#include <stdio.h>
#include <string.h>

typedef struct {
    char hash[256];
    char prev_hash[256];
} Block;

int validate_block(Block block, char* prev_hash, char* current_hash) {
    if (strcmp(block.hash, "") == 0 || strcmp(block.prev_hash, prev_hash) != 0) {
        return 0;
    }
    if (strcmp(current_hash, block.hash) != 0) {
        return 0;
    }
    return 1;
}

int verify_chain(Block* chain, int chain_length) {
    if (chain_length == 0) {
        return 0;
    }
    char prev_hash[256] = "genesis_hash";
    for (int i = 0; i < chain_length; i++) {
        if (!validate_block(chain[i], prev_hash, chain[i].hash)) {
            return 0;
        }
        strcpy(prev_hash, chain[i].hash);
    }
    return 1;
}

int main() {
    Block blockchain[3] = {
        {"block1_hash", "genesis_hash"},
        {"block2_hash", "block1_hash"},
        {"block3_hash", "block2_hash"}
    };
    printf("%d\n", verify_chain(blockchain, 3));
    return 0;
}