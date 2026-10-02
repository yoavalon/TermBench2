#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>

void simulate_cipher() {
    unsigned char key[32];
    if (!RAND_bytes(key, 32)) {
        fprintf(stderr, "Error generating random key\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        unsigned char data[64];
        if (!RAND_bytes(data, 64)) {
            fprintf(stderr, "Error generating random data\n");
            exit(EXIT_FAILURE);
        }

        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, 64, hash);

        unsigned char hmac[SHA256_DIGEST_LENGTH];
        unsigned int hmac_len;
        HMAC_CTX *hmac_ctx = HMAC_CTX_new();
        if (!hmac_ctx) {
            fprintf(stderr, "Error creating HMAC context\n");
            exit(EXIT_FAILURE);
        }
        HMAC_Init_ex(hmac_ctx, key, 32, EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, hash, SHA256_DIGEST_LENGTH);
        HMAC_Final_ex(hmac_ctx, hmac, &hmac_len);
        HMAC_CTX_free(hmac_ctx);

        for (int i = 0; i < hmac_len; i++) {
            printf("%02x", hmac[i]);
        }
        printf("\n");
    }
}

int main() {
    simulate_cipher();
    return 0;
}