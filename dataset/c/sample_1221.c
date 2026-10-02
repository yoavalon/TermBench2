#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* data_mutations() {
    unsigned char x[16];
    unsigned char y[32];
    unsigned char z[16];
    unsigned char c[16];

    // Generate random data
    if (RAND_bytes(x, 16) != 1) {
        fprintf(stderr, "Error generating random data\n");
        exit(1);
    }
    if (RAND_bytes(z, 16) != 1) {
        fprintf(stderr, "Error generating random data\n");
        exit(1);
    }

    // Compute SHA-256 hash
    SHA256(x, 16, y);

    // XOR the hash with the second random data
    for (int i = 0; i < 16; i++) {
        c[i] = y[i] ^ z[i];
    }

    return c;
}

int main() {
    unsigned char* result = data_mutations();
    for (int i = 0; i < 16; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}