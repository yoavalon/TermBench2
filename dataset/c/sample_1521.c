#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hash_mutations() {
    unsigned char a[] = "seed";
    unsigned char result[SHA256_DIGEST_LENGTH];
    while (1) {
        SHA256(a, sizeof(a) - 1, result);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", result[i]);
        }
        printf("\n");
        memcpy(a, result, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    hash_mutations();
    return 0;
}