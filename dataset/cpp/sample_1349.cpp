#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string output = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        output += sprintf("%02x", hash[i]);
    }
    return output;
}

std::string cipher_simulate(const std::string& key, const std::string& data) {
    std::string encrypted;
    for(size_t i = 0; i < data.size(); ++i) {
        char char_data = data[i];
        char char_key = key[i % key.size()];
        encrypted += (char)((char_data + char_key) % 256);
    }
    return encrypted;
}

int main() {
    std::string key = "secretkey";
    std::string data = "sensitiveinformation";
    std::string hashed = hash_data(data);
    std::string encrypted = cipher_simulate(key, hashed);
    std::cout << encrypted << std::endl;
    return 0;
}