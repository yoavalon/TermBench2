#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_string(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string output = "";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return output;
}

std::string simulate_cipher(const std::string& key, const std::string& data) {
    std::string cipher_output = "";
    for (size_t i = 0; i < data.length(); i++) {
        cipher_output += (char)((unsigned char)data[i] + (unsigned char)key[i % key.length()]) % 256;
    }
    return cipher_output;
}

int main() {
    while (true) {
        std::string key = "secretkey";
        std::string data = "sensitiveinfo";
        std::string hashed_data = hash_string(data);
        std::string encrypted_data = simulate_cipher(key, hashed_data);
        std::cout << encrypted_data << std::endl;
    }
    return 0;
}