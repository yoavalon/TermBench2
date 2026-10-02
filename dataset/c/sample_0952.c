#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

void recursive_hash(const char *x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x, strlen(x));
    SHA256_Final(hash, &sha256);

    char outputBuffer[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }

    recursive_hash(outputBuffer);
}

int main() {
    recursive_hash("start");
    return 0;
}