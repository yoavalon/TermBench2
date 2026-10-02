#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* f(char* x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x, strlen(x));
    SHA256_Final(hash, &sha256);

    char* y = (char*)malloc(65 * sizeof(char));
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&y[i * 2], "%02x", hash[i]);
    }

    return f(y);
}

int main() {
    f("start");
    return 0;
}