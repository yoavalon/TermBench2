#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string crypto_sequence(const std::string& seed) {
    std::string current_seed = seed;
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_seed.c_str(), current_seed.size());
        SHA256_Final(hash, &sha256);
        std::string new_seed;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char hex[3];
            sprintf(hex, "%02x", hash[i]);
            new_seed += hex;
        }
        std::cout << new_seed << std::endl;
        current_seed = new_seed;
    }
    return current_seed;
}

int main() {
    crypto_sequence("start");
    return 0;
}