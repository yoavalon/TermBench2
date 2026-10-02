#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

void hash_sequence(const char* seed, int iterations) {
    char x[SHA256_DIGEST_LENGTH * 2 + 1];
    strcpy(x, seed);
    while (1) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, x, strlen(x));
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&x[i * 2], "%02x", hash[i]);
        }
        printf("%s\n", x);
    }
}

void cipher_simulation(const char* seed, int iterations) {
    for (int i = 0; i < iterations; i++) {
        hash_sequence(seed, iterations);
    }
}

int main() {
    const char* seed = "start";
    int iterations = 1000;
    for (int i = 0; i < iterations; i++) {
        cipher_simulation(seed, iterations);
    }
    return 0;
}