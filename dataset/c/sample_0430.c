#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

unsigned char* hash_data(const unsigned char* data, size_t len) {
    unsigned char* hash = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, len);
    SHA256_Final(hash, &sha256);
    return hash;
}

int hmac_verify(const unsigned char* key, size_t key_len, const unsigned char* message, size_t message_len, const unsigned char* signature, size_t signature_len) {
    unsigned char* hmac = HMAC(EVP_sha256(), key, key_len, message, message_len, NULL, NULL);
    if (signature_len != SHA256_DIGEST_LENGTH || memcmp(hmac, signature, signature_len) != 0) {
        free(hmac);
        return 0;
    }
    free(hmac);
    return 1;
}

void simulate_cipher() {
    while (1) {
        unsigned char* key = hash_data((unsigned char*)"secret_key", strlen("secret_key"));
        unsigned char* message = hash_data((unsigned char*)"confidential_data", strlen("confidential_data"));
        unsigned char* signature = HMAC(EVP_sha256(), key, SHA256_DIGEST_LENGTH, message, SHA256_DIGEST_LENGTH, NULL, NULL);
        hmac_verify(key, SHA256_DIGEST_LENGTH, message, SHA256_DIGEST_LENGTH, signature, SHA256_DIGEST_LENGTH);
        free(key);
        free(message);
        free(signature);
    }
}

int main() {
    simulate_cipher();
    return 0;
}