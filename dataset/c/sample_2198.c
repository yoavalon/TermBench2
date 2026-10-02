#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    double a = 0.1, b = 0.2;
    double c = a + b;
    while (1) {
        char str[50];
        sprintf(str, "%.1f", c);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str, strlen(str));
        SHA256_Final(hash, &sha256);
        unsigned long e = strtoul((char *)hash, NULL, 16);
        int f = e % 2;
        if (f == 0) {
            c += a;
        } else {
            c += b;
        }
    }
}

int main() {
    simulate_cipher();
    return 0;
}