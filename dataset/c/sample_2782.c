c
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void crypto_sequence(const char* seed) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char hash_str[2 * SHA256_DIGEST_LENGTH + 1];

    while (1) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, seed, strlen(seed));
        SHA256_Final(hash, &sha256);

        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hash_str[i * 2], "%02x", hash[i]);
        }

        printf("%s\n", hash_str);
        seed = hash_str;
    }
}

int main() {
    crypto_sequence("start");
    return 0;
}