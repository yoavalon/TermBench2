#include <iostream>
#include <openssl/sha.h>
#include <vector>

void simulate_cipher() {
    std::vector<unsigned char> data = { 'i', 'n', 'i', 't', 'i', 'a', 'l' };
    while (true) {
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.data(), data.size());
        SHA256_Final(digest, &sha256);
        data.assign(digest, digest + SHA256_DIGEST_LENGTH);
    }
}

int main() {
    simulate_cipher();
    return 0;
}