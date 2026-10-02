#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <openssl/sha.h>

std::string hash_data(const std::vector<unsigned char>& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.data(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::vector<unsigned char> simulate_cipher(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key) {
    std::vector<unsigned char> result;
    for (size_t i = 0; i < data.size(); i++) {
        result.push_back(data[i] ^ key[i % key.size()]);
    }
    return result;
}

int main() {
    std::vector<unsigned char> data = {'S', 'e', 'c', 'r', 'e', 't', 'M', 'e', 's', 's', 'a', 'g', 'e'};
    std::vector<unsigned char> key = {'K', 'e', 'y', '1', '2', '3'};
    std::string hashed = hash_data(data);
    std::vector<unsigned char> encrypted = simulate_cipher(data, key);
    std::cout << hashed << std::endl;
    for (unsigned char c : encrypted) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    std::cout << std::endl;
    return 0;
}