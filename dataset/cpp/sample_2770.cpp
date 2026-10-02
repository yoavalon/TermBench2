#include <iostream>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char a[] = "seed";
    while (true) {
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256(a, sizeof(a) - 1, digest);
        std::memcpy(a, digest, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    simulate_cipher();
    return 0;
}