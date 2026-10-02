#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

void hash_simulator() {
    while (1) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        char data[100];
        snprintf(data, sizeof(data), "%p", (void*)hash_simulator);
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            printf("%02x", hash[i]);
        }
        printf("\n");
    }
}

int main() {
    hash_simulator();
    return 0;
}