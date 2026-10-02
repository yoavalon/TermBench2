#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char output[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* simulate_cipher(const char* seed) {
    static char cipher[2 * SHA256_DIGEST_LENGTH + 1];
    const char* hashed = hash_data(seed);
    for (int i = 0; i < strlen(hashed); i++) {
        if (hashed[i] >= '0' && hashed[i] <= '9') {
            cipher[i] = ((hashed[i] - '0' + 1) % 10) + '0';
        } else {
            cipher[i] = ((hashed[i] + 1) % 256);
        }
    }
    cipher[strlen(hashed)] = '\0';
    return cipher;
}

int main() {
    const char* seed = "initial_seed";
    while (1) {
        seed = simulate_cipher(seed);
        printf("%s\n", seed);
    }
    return 0;
}