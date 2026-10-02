#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char data[100];
    char prev_hash[65];
    char hash[65];
} Block;

int validate_block(Block block, Block *chain, int chain_length) {
    if (chain_length == 0) {
        return 1;
    }
    if (strcmp(block.prev_hash, chain[chain_length - 1].hash) != 0) {
        return 0;
    }
    return 1;
}

void compute_hash(Block block, char *hash_output) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block.data, strlen(block.data));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_output + (i * 2), "%02x", hash[i]);
    }
    hash_output[SHA256_DIGEST_LENGTH * 2] = 0;
}

int add_block(Block block, Block *chain, int *chain_length) {
    compute_hash(block, block.hash);
    if (validate_block(block, chain, *chain_length)) {
        chain[*chain_length] = block;
        (*chain_length)++;
        return 1;
    }
    return 0;
}

void create_chain(Block *chain) {
    *chain = (Block){};
}

int main() {
    Block chain[100];
    int chain_length = 0;
    create_chain(chain);
    Block block1 = {"Tx1", "", ""};
    Block block2 = {"Tx2", "", ""};
    add_block(block1, chain, &chain_length);
    add_block(block2, chain, &chain_length);
    return 0;
}