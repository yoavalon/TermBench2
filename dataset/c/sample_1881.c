#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

unsigned char* process(const char* data) {
    static unsigned char message[SHA256_DIGEST_LENGTH];
    for (int i = 0; i < 100; i++) {
        unsigned char key[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        char str_i[12];
        sprintf(str_i, "%d", i);
        SHA256_Update(&sha256, str_i, strlen(str_i));
        SHA256_Final(key, &sha256);

        HMAC_CTX* hmac_ctx = HMAC_CTX_new();
        HMAC_Init_ex(hmac_ctx, key, SHA256_DIGEST_LENGTH, EVP_sha256(), NULL);
        HMAC_Update(hmac_ctx, data, strlen(data));
        HMAC_Final_ex(hmac_ctx, message, &SHA256_DIGEST_LENGTH);
        HMAC_CTX_free(hmac_ctx);
    }
    return message;
}

int main() {
    unsigned char* result = process("securedata");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
    return 0;
}