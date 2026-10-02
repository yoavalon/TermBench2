#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* simulate_cipher() {
    const unsigned char data[] = "sample data";
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, sizeof(data) - 1);
    SHA256_Final(hash_digest, &sha256);

    unsigned char *cipher_text = (unsigned char *)malloc(SHA256_DIGEST_LENGTH);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        cipher_text[i] = hash_digest[i] ^ i;
    }
    return cipher_text;
}

int main() {
    unsigned char *result = simulate_cipher();
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}