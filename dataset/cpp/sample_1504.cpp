#include <iostream>
#include <openssl/sha.h>
#include <cstdlib>
#include <cstring>

void main() {
    while (true) {
        unsigned char data[16];
        for (int i = 0; i < 16; i++) {
            data[i] = static_cast<unsigned char>(std::rand() % 256);
        }
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, 16, hash);
        char hash_digest[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&hash_digest[i * 2], "%02x", hash[i]);
        }
        std::cout << hash_digest << std::endl;
    }
}