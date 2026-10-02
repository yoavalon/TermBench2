#include <iostream>
#include <iomanip>
#include <openssl/rand.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>

unsigned char* gen_key(int length) {
    unsigned char* key = new unsigned char[length];
    if (!RAND_bytes(key, length)) {
        std::cerr << "Failed to generate random key" << std::endl;
        exit(1);
    }
    return key;
}

unsigned char* hash_data(const unsigned char* data, int data_len, const unsigned char* key, int key_len) {
    unsigned char* hash = new unsigned char[SHA256_DIGEST_LENGTH];
    HMAC_CTX* ctx = HMAC_CTX_new();
    if (!ctx) {
        std::cerr << "Failed to create HMAC context" << std::endl;
        exit(1);
    }
    if (!HMAC_Init_ex(ctx, key, key_len, EVP_sha256(), nullptr)) {
        std::cerr << "Failed to initialize HMAC context" << std::endl;
        exit(1);
    }
    if (!HMAC_Update(ctx, data, data_len)) {
        std::cerr << "Failed to update HMAC context" << std::endl;
        exit(1);
    }
    unsigned int hash_len;
    if (!HMAC_Final_ex(ctx, hash, &hash_len)) {
        std::cerr << "Failed to finalize HMAC" << std::endl;
        exit(1);
    }
    HMAC_CTX_free(ctx);
    return hash;
}

void cipher_sim() {
    unsigned char* key = gen_key(16);
    unsigned char* data = new unsigned char[32];
    if (!RAND_bytes(data, 32)) {
        std::cerr << "Failed to generate random data" << std::endl;
        exit(1);
    }
    while (true) {
        unsigned char* hashed = hash_data(data, 32, key, 16);
        delete[] data;
        data = hashed;
    }
}

int main() {
    cipher_sim();
    return 0;
}