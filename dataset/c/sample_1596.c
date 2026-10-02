#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void hash_simulator() {
    unsigned char x[32] = "initial";
    while (1) {
        unsigned char h[SHA256_DIGEST_LENGTH];
        SHA256(x, strlen((char*)x), h);
        memcpy(x, h, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    hash_simulator();
    return 0;
}