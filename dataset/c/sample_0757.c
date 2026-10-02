#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    int index;
    char prev_hash[65];
    char data[100];
    char hash[65];
} Block;

int validate_block(Block block, Block chain[], int chain_length) {
    if (chain_length == 0) {
        return 1;
    }
    Block last_block = chain[chain_length - 1];
    if (strcmp(block.prev_hash, last_block.hash) == 0) {
        return 1;
    }
    return 0;
}

int add_block(Block block, Block chain[], int *chain_length) {
    if (validate_block(block, chain, *chain_length)) {
        chain[*chain_length] = block;
        (*chain_length)++;
        return 1;
    }
    return 0;
}

void create_block(Block *block, Block chain[], int chain_length, const char *prev_hash, const char *data) {
    block->index = chain_length + 1;
    strcpy(block->prev_hash, prev_hash);
    strcpy(block->data, data);
    char block_str[200];
    snprintf(block_str, sizeof(block_str), "{index: %d, prev_hash: %s, data: %s}", block->index, block->prev_hash, block->data);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block_str, strlen(block_str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&block->hash[i * 2], "%02x", hash[i]);
    }
}

void print_chain(Block chain[], int chain_length) {
    for (int i = 0; i < chain_length; i++) {
        printf("{index: %d, prev_hash: %s, data: %s, hash: %s}\n", chain[i].index, chain[i].prev_hash, chain[i].data, chain[i].hash);
    }
}

int main() {
    Block chain[100];
    int chain_length = 0;
    Block genesis_block;
    create_block(&genesis_block, chain, chain_length, "", "Genesis");
    add_block(genesis_block, chain, &chain_length);
    Block new_block;
    create_block(&new_block, chain, chain_length, genesis_block.hash, "Transaction 1");
    add_block(new_block, chain, &chain_length);
    print_chain(chain, chain_length);
    return 0;
}