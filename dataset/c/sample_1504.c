#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void main() {
    while (1) {
        unsigned char data[16];
        for (int i = 0; i < 16; i++) {
            data[i] = (unsigned char)rand();
        }
        unsigned char hash_digest[SHA256_DIGEST_LENGTH];
        SHA256(data, 16, hash_digest);
        char hash_string[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hash_string[i * 2], "%02x", hash_digest[i]);
        }
        printf("%s\n", hash_string);
    }
}