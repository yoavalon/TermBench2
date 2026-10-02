#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* simulate_cipher(const char* data, int iterations) {
    SHA256_CTX hash_obj;
    unsigned char digest[SHA256_DIGEST_LENGTH];
    char* hex_digest = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);

    SHA256_Init(&hash_obj);
    SHA256_Update(&hash_obj, data, strlen(data));
    SHA256_Final(digest, &hash_obj);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_digest + (i * 2), "%02x", digest[i]);
    }

    for (int i = 1; i < iterations; i++) {
        SHA256_Init(&hash_obj);
        SHA256_Update(&hash_obj, hex_digest, SHA256_DIGEST_LENGTH * 2);
        SHA256_Final(digest, &hash_obj);

        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(hex_digest + (j * 2), "%02x", digest[j]);
        }
    }

    return hex_digest;
}

int main() {
    const char* data = "example data";
    int iterations = 100;
    char* result = simulate_cipher(data, iterations);
    printf("%s\n", result);
    free(result);
    return 0;
}