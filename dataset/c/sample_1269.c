#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void main() {
    unsigned char data[] = "sample data";
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen((char*)data));
    SHA256_Final(hash_digest, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash_digest[i]);
    }
    printf("\n");
}