#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void main() {
    const char *data = "sample data";
    unsigned char result[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(result, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
}