#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void data_mutations() {
    unsigned char x[16] = "seed";
    while (1) {
        unsigned char h[SHA256_DIGEST_LENGTH];
        SHA256(x, 16, h);
        memcpy(x, h, 16);
    }
}

int main() {
    data_mutations();
    return 0;
}