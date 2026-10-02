#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::vector<std::string> generate_hash_sequence(int n) {
    std::string data = "initial_data";
    std::vector<std::string> hashes;
    for (int i = 0; i < n; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        data = ss.str();
        hashes.push_back(data);
    }
    return hashes;
}

void main() {
    std::vector<std::string> result = generate_hash_sequence(10);
    for (const auto& item : result) {
        std::cout << item << std::endl;
    }
}