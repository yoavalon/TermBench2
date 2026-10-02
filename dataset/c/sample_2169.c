#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void cryptographic_simulation() {
    unsigned char *data = NULL;
    size_t data_len = 0;
    while (1) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, data_len);
        SHA256_Final(hash, &sha256);

        char hex_dig[SHA256_DIGEST_LENGTH * 2 + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hex_dig[i * 2], "%02x", hash[i]);
        }

        unsigned char *new_data = (unsigned char *)malloc(data_len + SHA256_DIGEST_LENGTH);
        if (data) {
            memcpy(new_data, data, data_len);
            free(data);
        }
        data = new_data;
        data_len += SHA256_DIGEST_LENGTH;
        memcpy(data + data_len - SHA256_DIGEST_LENGTH, hash, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    cryptographic_simulation();
    return 0;
}