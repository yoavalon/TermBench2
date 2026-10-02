#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_cipher(const std::string& data, int iterations) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);

    std::string hex = "";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        hex += buffer;
    }

    for (int i = 1; i < iterations; ++i) {
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, hex.c_str(), hex.size());
        SHA256_Final(hash, &sha256);

        hex = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buffer[3];
            sprintf(buffer, "%02x", hash[i]);
            hex += buffer;
        }
    }

    return hex;
}

int main() {
    std::string result = hash_cipher("test_data", 5);
    std::cout << result << std::endl;
    return 0;
}