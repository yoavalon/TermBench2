#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_function(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char outputBuffer[65];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    return outputBuffer;
}

int consensus_mechanism(char** blockchain, int* blockchain_size, const char* new_block) {
    char* block_hash = hash_function(new_block);
    blockchain[*blockchain_size] = strdup(block_hash);
    (*blockchain_size)++;
    if (*blockchain_size >= 10) {
        return 1;
    }
    return 0;
}

void main() {
    char* blockchain[15];
    int blockchain_size = 0;
    for (int i = 0; i < 15; i++) {
        char new_block[10];
        sprintf(new_block, "Block_%d", i);
        if (consensus_mechanism(blockchain, &blockchain_size, new_block)) {
            break;
        }
    }
}