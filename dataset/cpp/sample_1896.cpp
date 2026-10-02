#include <iostream>
#include <openssl/sha.h>
#include <string>

std::string process_data(const std::string& data) {
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash_digest, &sha256);
    return std::string(reinterpret_cast<char*>(hash_digest), 16);
}

int main() {
    std::string data = "Sample data for cryptographic hashing";
    std::string result = process_data(data);
    for (char c : result) {
        std::cout << std::hex << (int)c;
    }
    return 0;
}