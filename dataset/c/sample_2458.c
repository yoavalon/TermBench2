#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* simulate_cipher_sequence(unsigned char* data, size_t data_len, int iterations) {
    unsigned char* result = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    if (!result) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memcpy(result, data, data_len);
    for (int i = 0; i < iterations; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(result, data_len, hash);
        memcpy(result, hash, SHA256_DIGEST_LENGTH);
        data_len = SHA256_DIGEST_LENGTH;
    }
    return result;
}

int main() {
    unsigned char initial_data[] = "hello";
    int iterations = 5;
    unsigned char* result = simulate_cipher_sequence(initial_data, sizeof(initial_data) - 1, iterations);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}