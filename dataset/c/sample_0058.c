#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* boundary_conditions(unsigned char* data, size_t length) {
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, length);
    SHA256_Final(hash_digest, &sha256);

    static char hex_string[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_string + (i * 2), "%02x", hash_digest[i]);
    }
    return hex_string;
}

int main() {
    unsigned char data[] = "hello_world";
    size_t length = strlen((char*)data);
    char* result = boundary_conditions(data, length);
    printf("%s\n", result);
    return 0;
}