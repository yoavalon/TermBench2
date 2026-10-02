#include <iostream>
#include <vector>
#include <openssl/sha.h>

std::vector<unsigned char> simulate_cipher() {
    std::string data = "sample data";
    unsigned char hash_digest[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash_digest);
    std::vector<unsigned char> cipher_text;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        cipher_text.push_back(hash_digest[i] ^ i);
    }
    return cipher_text;
}

int main() {
    auto result = simulate_cipher();
    for (auto byte : result) {
        std::cout << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;
    return 0;
}