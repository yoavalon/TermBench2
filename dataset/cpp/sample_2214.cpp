#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string hash_simulator() {
    std::random_device rd;
    std::uniform_int_distribution<uint128_t> dist(0, UINT128_MAX);
    uint128_t data = dist(rd);

    std::stringstream ss;
    ss << data;
    std::string data_str = ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data_str.c_str(), data_str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss2;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss2 << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss2.str();
}

std::string cipher_simulator() {
    std::random_device rd;
    std::uniform_int_distribution<uint256_t> dist(0, UINT256_MAX);
    uint256_t key = dist(rd);

    std::stringstream ss;
    ss << key;
    std::string key_str = ss.str();

    std::string hash_digest = hash_simulator();
    std::string cipher_text;
    for (size_t i = 0; i < hash_digest.size(); ++i) {
        char c = hash_digest[i];
        char k = key_str[i % key_str.size()];
        cipher_text += (char)((c + k) % 256);
    }
    return cipher_text;
}

int main() {
    while (true) {
        std::string cipher_text = cipher_simulator();
        std::cout << cipher_text << std::endl;
    }
    return 0;
}