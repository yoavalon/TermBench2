#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    static char hash[65];
    unsigned char hash_output[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash_output, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hash[i * 2], "%02x", hash_output[i]);
    }
    return hash;
}

void main() {
    const char* data = "cryptographic_hashing";
    char* hashed = hash_data(data);
    printf("%s\n", hashed);
}