#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string simulate_cipher(const std::string& data, int iterations = 100) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string digest;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buf[3];
        sprintf(buf, "%02x", hash[i]);
        digest.append(buf);
    }
    for (int i = 1; i < iterations; ++i) {
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, digest.c_str(), digest.size());
        SHA256_Final(hash, &sha256);
        digest.clear();
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buf[3];
            sprintf(buf, "%02x", hash[i]);
            digest.append(buf);
        }
    }
    return digest;
}

int main() {
    std::string result = simulate_cipher("example data");
    std::cout << result << std::endl;
    return 0;
}