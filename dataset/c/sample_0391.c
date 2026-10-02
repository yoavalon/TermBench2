#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char a[] = "initial data";
    unsigned char hash[SHA256_DIGEST_LENGTH];

    while (1) {
        SHA256(a, strlen(a), hash);
        memcpy(a, hash, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    simulate_cipher();
    return 0;
}