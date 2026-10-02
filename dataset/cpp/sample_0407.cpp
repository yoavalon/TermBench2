#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void simulate_cipher(const std::string& hash_result) {
    while (true) {
        std::string new_hash = hash_data(hash_result);
        if (new_hash == hash_result) {
            break;
        }
        hash_result = new_hash;
    }
}

int main() {
    std::string initial_data = "seed";
    std::string hash_result = hash_data(initial_data);
    simulate_cipher(hash_result);
    return 0;
}