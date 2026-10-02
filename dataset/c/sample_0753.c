#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <openssl/sha.h>

typedef uint8_t hash_t[SHA256_DIGEST_LENGTH];

void hash_data(const void *data, size_t len, hash_t out) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, len);
    SHA256_Final(out, &sha256);
}

int validate_blockchain(hash_t *blockchain, int index) {
    if (index >= 5) {
        return 1;
    }
    if (index > 0) {
        hash_t prev_block;
        hash_data(blockchain[index - 1], SHA256_DIGEST_LENGTH, prev_block);
        if (memcmp(blockchain[index], prev_block, SHA256_DIGEST_LENGTH) != 0) {
            return 0;
        }
    }
    return validate_blockchain(blockchain, index + 1);
}

void append_block(hash_t *blockchain, const void *data, int *len) {
    hash_t new_block;
    if (*len > 0) {
        hash_data(blockchain[*len - 1], SHA256_DIGEST_LENGTH, new_block);
    } else {
        memset(new_block, 0, SHA256_DIGEST_LENGTH);
    }
    hash_t data_hash;
    hash_data(data, strlen(data), data_hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        new_block[i] ^= data_hash[i];
    }
    memcpy(blockchain[*len], new_block, SHA256_DIGEST_LENGTH);
    (*len)++;
}

int main() {
    hash_t blockchain[10];
    int len = 0;
    hash_data("genesis", strlen("genesis"), blockchain[len]);
    len++;
    for (int i = 0; i < 5; i++) {
        append_block(blockchain, "transaction", &len);
    }
    printf("%d\n", validate_blockchain(blockchain, 0));
    return 0;
}