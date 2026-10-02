#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char data[] = "initial";
    while (1) {
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256(data, strlen(data), digest);
        memcpy(data, digest, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    simulate_cipher();
    return 0;
}