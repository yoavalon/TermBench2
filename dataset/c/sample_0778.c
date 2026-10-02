#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char data[20];
    char previous_hash[20];
    char hash[20];
} Block;

bool validate_block(Block block, Block blockchain[], int size) {
    if (block.hash[0] == '\0') return true;
    for (int i = 0; i < size; i++) {
        if (strcmp(blockchain[i].hash, block.hash) == 0) return false;
    }
    char prev_hash[20] = "";
    if (size > 0) strcpy(prev_hash, blockchain[size - 1].hash);
    if (strcmp(block.previous_hash, prev_hash) != 0) return false;
    return true;
}

bool add_block(Block block, Block blockchain[], int *size) {
    if (validate_block(block, blockchain, *size)) {
        strcpy(blockchain[(*size)++].hash, block.hash);
        return true;
    }
    return false;
}

int main() {
    Block blockchain[10];
    int size = 0;

    Block block1 = {"tx1", "", "hash1"};
    Block block2 = {"tx2", "hash1", "hash2"};
    Block block3 = {"tx3", "hash2", "hash3"};
    Block block4 = {"tx4", "hash3", "hash4"};

    Block blocks[] = {block1, block2, block3, block4};

    for (int i = 0; i < 4; i++) {
        add_block(blocks[i], blockchain, &size);
    }

    for (int i = 0; i < size; i++) {
        printf("%s\n", blockchain[i].hash);
    }

    return 0;
}