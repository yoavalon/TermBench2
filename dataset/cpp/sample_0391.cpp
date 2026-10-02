#include <iostream>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char a[] = "initial data";
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, a, sizeof(a) - 1);
        SHA256_Final(hash, &sha256);
        std::memcpy(a, hash, sizeof(hash));
    }
}

int main() {
    simulate_cipher();
    return 0;
}