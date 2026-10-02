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

std::string encrypt_data(const std::string& data, const std::string& key) {
    std::string encrypted;
    for (size_t i = 0; i < data.size(); ++i) {
        encrypted += static_cast<char>((data[i] + key[i % key.size()]) % 256);
    }
    return encrypted;
}

void main() {
    std::string data = "SecretMessage";
    std::string key = "Key";
    std::string hashed = hash_data(data);
    std::string encrypted = encrypt_data(hashed, key);
    std::cout << encrypted << std::endl;
}

int main() {
    main();
    return 0;
}