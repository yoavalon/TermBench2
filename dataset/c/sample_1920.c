#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

unsigned char* hash_data(const unsigned char* data, size_t data_len, unsigned char* hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);
    return hash;
}

unsigned char* cipher_simulate(const unsigned char* key, size_t key_len, const unsigned char* message, size_t message_len, unsigned char* encrypted) {
    HMAC_CTX *ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, key, key_len, EVP_sha256(), NULL);
    HMAC_Update(ctx, message, message_len);
    HMAC_Final_ex(ctx, encrypted, &message_len);
    HMAC_CTX_free(ctx);
    return encrypted;
}

int main() {
    unsigned char data[] = "secret_data";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    hash_data(data, strlen((char*)data), hash);

    unsigned char key[] = "cipher_key";
    unsigned char encrypted[EVP_MAX_MD_SIZE];
    cipher_simulate(key, strlen((char*)key), hash, SHA256_DIGEST_LENGTH, encrypted);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    return 0;
}