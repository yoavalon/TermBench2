#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

unsigned char* gen_key(int length) {
    unsigned char* key = malloc(length);
    if (RAND_bytes(key, length) != 1) {
        fprintf(stderr, "Failed to generate random key\n");
        exit(1);
    }
    return key;
}

unsigned char* hash_data(const unsigned char* data, int data_len, const unsigned char* key, int key_len) {
    unsigned char* hashed = malloc(SHA256_DIGEST_LENGTH);
    if (HMAC(EVP_sha256(), key, key_len, data, data_len, hashed, NULL) == NULL) {
        fprintf(stderr, "Failed to hash data\n");
        exit(1);
    }
    return hashed;
}

void cipher_sim() {
    unsigned char* key = gen_key(16);
    unsigned char* data = malloc(32);
    if (RAND_bytes(data, 32) != 1) {
        fprintf(stderr, "Failed to generate random data\n");
        exit(1);
    }
    while (1) {
        unsigned char* hashed = hash_data(data, 32, key, 16);
        free(data);
        data = hashed;
    }
}

int main() {
    cipher_sim();
    return 0;
}