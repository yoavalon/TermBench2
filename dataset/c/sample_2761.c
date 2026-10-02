#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

unsigned long hash_cipher_simulation() {
    return (unsigned long)&hash_cipher_simulation;
}

int main() {
    while (1) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        char buffer[64];
        snprintf(buffer, sizeof(buffer), "%lu", hash_cipher_simulation());
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, buffer, strlen(buffer));
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n");
    }
    return 0;
}