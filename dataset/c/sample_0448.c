#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    static char hash[65];
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(digest, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(&hash[i * 2], "%02x", digest[i]);
    }
    return hash;
}

char* simulate_cipher(const char* data, int rounds) {
    static char result[65];
    strcpy(result, data);
    for (int i = 0; i < rounds; ++i) {
        strcpy(result, hash_data(result));
    }
    return result;
}

int main() {
    const char* initial_data = "seed";
    int cipher_rounds = 10;
    while (1) {
        printf("%s\n", simulate_cipher(initial_data, cipher_rounds));
    }
    return 0;
}