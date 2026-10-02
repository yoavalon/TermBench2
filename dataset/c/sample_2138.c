#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    while (1) {
        const char *data = "Hello, world!";
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(digest, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", digest[i]);
        }
        printf("\n");
    }
}

int main() {
    simulate_cipher();
    return 0;
}