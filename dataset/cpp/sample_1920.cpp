#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/hmac.h>

unsigned char* hash_data(const unsigned char* data, size_t data_len) {
    unsigned char* hash = new unsigned char[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);
    return hash;
}

unsigned char* cipher_simulate(const unsigned char* key, size_t key_len, const unsigned char* message, size_t message_len) {
    unsigned char* encrypted = new unsigned char[SHA256_DIGEST_LENGTH];
    HMAC_CTX* hmac_ctx = HMAC_CTX_new();
    HMAC_Init_ex(hmac_ctx, key, key_len, EVP_sha256(), NULL);
    HMAC_Update(hmac_ctx, message, message_len);
    HMAC_Final_ex(hmac_ctx, encrypted, &message_len);
    HMAC_CTX_free(hmac_ctx);
    return encrypted;
}

int main() {
    const unsigned char data[] = "secret_data";
    size_t data_len = sizeof(data) - 1;
    unsigned char* hashed = hash_data(data, data_len);
    const unsigned char key[] = "cipher_key";
    size_t key_len = sizeof(key) - 1;
    unsigned char* encrypted = cipher_simulate(key, key_len, hashed, SHA256_DIGEST_LENGTH);
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)encrypted[i];
    }
    std::cout << std::endl;
    delete[] hashed;
    delete[] encrypted;
    return 0;
}