#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_recursive(const char* data, const char* salt, double rounds) {
    if (rounds > 0) {
        char* combined = malloc(strlen(data) + strlen(salt) + 1);
        strcpy(combined, data);
        strcat(combined, salt);

        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, combined, strlen(combined));
        SHA256_Final(hash, &sha256);

        char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hash_str[i * 2], "%02x", hash[i]);
        }

        free(combined);
        return hash_recursive(hash_str, salt, rounds - 1);
    }
    return strdup(data);
}

int main() {
    hash_recursive("data", "salt", INFINITY);
    return 0;
}