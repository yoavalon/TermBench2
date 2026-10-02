#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void main() {
    char x[] = "hello";
    unsigned char y[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x, strlen(x));
    SHA256_Final(y, &sha256);
    char z[65];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&z[i * 2], "%02x", y[i]);
    }
    for (int i = 0; i < SHA256_DIGEST_LENGTH * 2; i++) {
        z[i] = z[SHA256_DIGEST_LENGTH * 2 - i - 1];
    }
    printf("%s\n", z);
}