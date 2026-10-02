#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::vector<std::string> generate_hash_sequence(const std::string& seed, int length) {
    std::vector<std::string> sequence;
    std::string current_seed = seed;
    for (int i = 0; i < length; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_seed.c_str(), current_seed.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int j = 0; j < SHA256_DIGEST_LENGTH; ++j) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[j];
        }
        sequence.push_back(ss.str());
        current_seed = ss.str();
    }
    return sequence;
}

int main() {
    std::vector<std::string> result = generate_hash_sequence("start", 10);
    for (const auto& hash : result) {
        std::cout << hash << std::endl;
    }
    return 0;
}