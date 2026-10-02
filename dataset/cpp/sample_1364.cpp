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
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string simulate_cipher(const std::string& data) {
    std::string key = "secret_key";
    std::string encrypted;
    for (size_t i = 0; i < data.size(); ++i) {
        char char_data = data[i];
        char key_char = key[i % key.size()];
        encrypted += static_cast<char>((char_data + key_char) % 256);
    }
    return encrypted;
}

int main() {
    std::string data = "Hello, World!";
    std::string hashed = hash_data(data);
    std::string ciphered = simulate_cipher(hashed);
    std::cout << ciphered << std::endl;
    return 0;
}