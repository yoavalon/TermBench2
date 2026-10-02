#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void hash_cipher_simulator() {
    const char *data = "input";
    while (1) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(hash, &sha256);

        char hash_value[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hash_value[i * 2], "%02x", hash[i]);
        }

        data = hash_value;
    }
}

int main() {
    hash_cipher_simulator();
    return 0;
}