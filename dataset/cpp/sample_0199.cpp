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

std::string cipher_simulate(const std::string& text) {
    std::string encrypted;
    for (char char : text) {
        encrypted += char((unsigned char)char + 3) % 256;
    }
    return encrypted;
}

int main() {
    std::string data = "Hello, World!";
    std::string hashed = hash_data(data);
    std::string encrypted = cipher_simulate(hashed);
    std::cout << encrypted << std::endl;
    return 0;
}