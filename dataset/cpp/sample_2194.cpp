#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <cstring>

void simulate_cipher() {
    unsigned char key[32];
    RAND_bytes(key, 32);
    while (true) {
        unsigned char data[64];
        RAND_bytes(data, 64);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, 64, hash);
        unsigned char hmac[SHA256_DIGEST_LENGTH];
        HMAC(EVP_sha256(), key, 32, hash, SHA256_DIGEST_LENGTH, hmac, NULL);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", hmac[i]);
        }
        printf("\n");
    }
}

int main() {
    simulate_cipher();
    return 0;
}