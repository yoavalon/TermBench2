#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    int index;
    char *data;
    char *previous_hash;
    char *hash;
} Block;

int validate_block(Block block, Block *chain, int chain_length) {
    if (chain_length == 0) {
        return 1;
    }
    Block last_block = chain[chain_length - 1];
    return strcmp(block.previous_hash, last_block.hash) == 0;
}

void add_block(Block *chain, int *chain_length, const char *data) {
    Block block;
    block.index = *chain_length;
    block.data = strdup(data);
    block.previous_hash = (*chain_length == 0) ? strdup("0") : strdup(chain[*chain_length - 1].hash);
    
    char input[256];
    sprintf(input, "%d%s%s", *chain_length, data, block.previous_hash);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);
    block.hash = malloc(2 * SHA256_DIGEST_LENGTH + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(block.hash + (i * 2), "%02x", hash[i]);
    }
    
    if (validate_block(block, chain, *chain_length)) {
        chain[*chain_length] = block;
        (*chain_length)++;
    }
    add_block(chain, chain_length, data);
}

void main() {
    Block ledger[100];
    int chain_length = 0;
    add_block(ledger, &chain_length, "Genesis Block");
    add_block(ledger, &chain_length, "Transaction Data");
}