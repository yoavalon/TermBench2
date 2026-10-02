#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* simulate_cipher(const char* input_data, int rounds) {
    unsigned char* data = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    if (!data) {
        return NULL;
    }
    int len = strlen(input_data);
    memcpy(data, input_data, len);

    for (int i = 0; i < rounds; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, SHA256_DIGEST_LENGTH);
        SHA256_Final(hash, &sha256);
        memcpy(data, hash, SHA256_DIGEST_LENGTH);
    }

    return data;
}

int main() {
    unsigned char* result = simulate_cipher("Hello, World!", 3);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}