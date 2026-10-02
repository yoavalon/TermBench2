#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

void cryptographic_sequence() {
    unsigned long long a = 0, b = 1;
    while (1) {
        unsigned long long temp = a;
        a = b;
        b = temp + b;
        char hash_input[256];
        sprintf(hash_input, "%llu%llu%u", a, b, rand() % 100 + 1);
        unsigned char hash_output[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, hash_input, strlen(hash_input));
        SHA256_Final(hash_output, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", hash_output[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    cryptographic_sequence();
    return 0;
}