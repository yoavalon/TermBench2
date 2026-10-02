#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int func(const char *a, const char *b) {
    unsigned char x[SHA256_DIGEST_LENGTH];
    unsigned char y[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, a, strlen(a));
    SHA256_Final(x, &sha256);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, b, strlen(b));
    SHA256_Final(y, &sha256);
    return memcmp(x, y, SHA256_DIGEST_LENGTH) == 0;
}

int main() {
    const char *a = "hello";
    const char *b = "world";
    int result = func(a, b);
    printf("%d\n", result);
    return 0;
}