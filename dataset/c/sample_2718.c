#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void crypto_simulator() {
    int a = 0, b = 1;
    while (1) {
        char data[33];
        sprintf(data, "%d%d", a, b);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(hash, &sha256);
        char hex_dig[33];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(hex_dig + (i * 2), "%02x", hash[i]);
        }
        a = b;
        b = strtoul(hex_dig, NULL, 16) >> 16;
    }
}

int main() {
    crypto_simulator();
    return 0;
}