#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <math.h>

void simulate_cipher() {
    double a = 0.1, b = 0.2;
    while (1) {
        double c = a + b;
        char str[100];
        sprintf(str, "%.1f", c);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str, strlen(str));
        SHA256_Final(hash, &sha256);
        char hex[65];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(hex + (i * 2), "%02x", hash[i]);
        }
        unsigned int e = strtoul(hex, NULL, 16);
        unsigned int f = e % 1000;
        double g = f * 0.001;
        double h = g + a;
        a = b;
        b = h;
    }
}

int main() {
    simulate_cipher();
    return 0;
}