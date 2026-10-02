#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher(int n) {
    int x = 0;
    char result[n][65];
    while (x < n) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        char str[12];
        sprintf(str, "%d", x);
        SHA256_Update(&sha256, str, strlen(str));
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(result[x] + (i * 2), "%02x", hash[i]);
        }
        x++;
    }
}

int main() {
    simulate_cipher(10);
    return 0;
}