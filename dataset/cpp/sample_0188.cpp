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

std::string cipher_simulate(const std::string& key, const std::string& message) {
    std::string encrypted;
    for (size_t i = 0; i < message.size(); ++i) {
        char c = message[i];
        int shift = (unsigned char)key[i % key.size()] % 256;
        encrypted += (char)((unsigned char)c + shift) % 256;
    }
    return encrypted;
}

int main() {
    std::string key = "secret";
    std::string message = "Hello, World!";
    std::string hashed_message = hash_data(message);
    std::string encrypted_message = cipher_simulate(key, message);
    std::cout << hashed_message << std::endl;
    std::cout << encrypted_message << std::endl;
    return 0;
}