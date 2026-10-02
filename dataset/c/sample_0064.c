#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* simulate_cipher(unsigned char* data, int iterations) {
    for (int i = 0; i < iterations; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, strlen((char*)data), hash);
        data = hash;
    }
    return data;
}

int main() {
    unsigned char initial_data[] = "initial data";
    unsigned char result[SHA256_DIGEST_LENGTH];
    simulate_cipher(initial_data, 10);
    printf("%s\n", result);
    return 0;
}