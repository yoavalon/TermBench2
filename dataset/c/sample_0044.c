#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_cipher(const char* data, int iterations) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);

    char* hex_string = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_string + i * 2, "%02x", hash[i]);
    }

    for (int i = 0; i < iterations - 1; i++) {
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, hex_string, SHA256_DIGEST_LENGTH * 2);
        SHA256_Final(hash, &sha256);

        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(hex_string + j * 2, "%02x", hash[j]);
        }
    }

    return hex_string;
}

int main() {
    char* result = hash_cipher("test_data", 5);
    printf("%s\n", result);
    free(result);
    return 0;
}