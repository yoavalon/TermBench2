#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string crypto_simulator(const std::string& data) {
    std::string current_data = data;
    for (int i = 0; i < 10; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_data.c_str(), current_data.size());
        SHA256_Final(hash, &sha256);
        current_data = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            current_data += std::to_string((unsigned int)hash[i]);
        }
    }
    return current_data;
}

int main() {
    crypto_simulator("initial_data");
    return 0;
}