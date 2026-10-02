#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void simulate_cipher() {
    while (1) {
        const char *data = "secret_message";
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, strlen(data));
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n");
    }
}

int main() {
    simulate_cipher();
    return 0;
}