#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void crypto_simulator(const char* data) {
    char buffer[2 * SHA256_DIGEST_LENGTH + 1];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    const char* current_data = data;

    for (int i = 0; i < 10; i++) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_data, strlen(current_data));
        SHA256_Final(hash, &sha256);

        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&buffer[j * 2], "%02x", hash[j]);
        }
        buffer[2 * SHA256_DIGEST_LENGTH] = 0;
        current_data = buffer;
    }

    printf("%s\n", current_data);
}

int main() {
    crypto_simulator("initial_data");
    return 0;
}