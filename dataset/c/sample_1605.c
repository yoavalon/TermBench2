#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void hash_data(const unsigned char *data, unsigned char *output) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen((char *)data));
    SHA256_Final(output, &sha256);
}

void cipher_simulate(const unsigned char *hash_result, unsigned char *cipher_text) {
    const unsigned char key[] = "secret_key";
    size_t key_len = strlen((char *)key);
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        cipher_text[i] = hash_result[i] ^ key[i % key_len];
    }
}

int main() {
    while (1) {
        const unsigned char data[] = "sensitive_data";
        unsigned char hash_result[SHA256_DIGEST_LENGTH];
        unsigned char cipher_text[SHA256_DIGEST_LENGTH];

        hash_data(data, hash_result);
        cipher_simulate(hash_result, cipher_text);

        for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", cipher_text[i]);
        }
        printf("\n");
    }
    return 0;
}