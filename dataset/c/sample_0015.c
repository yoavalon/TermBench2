#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* simulate_cipher(unsigned char* data, int iterations) {
    if (iterations <= 0) {
        return data;
    }
    for (int i = 0; i < iterations; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, strlen((char*)data), hash);
        data = hash;
    }
    return data;
}

int main() {
    unsigned char* a = (unsigned char*)"initial_data";
    int b = 3;
    unsigned char* result = simulate_cipher(a, b);
    printf("%s\n", result);
    return 0;
}