#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void hash_simulator() {
    unsigned char a[] = "abc";
    unsigned char h[SHA256_DIGEST_LENGTH];
    char hash_str[2 * SHA256_DIGEST_LENGTH + 1];

    while (1) {
        SHA256(a, strlen((char *)a), h);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hash_str[i * 2], "%02x", h[i]);
        }
        strcpy((char *)a, hash_str);
    }
}

int main() {
    hash_simulator();
    return 0;
}