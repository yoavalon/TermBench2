#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string generate_hash(const std::string& data) {
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

std::string simulate_cipher(const std::string& hash_val) {
    std::string key = "secret";
    std::string cipher_text = "";
    for (size_t i = 0; i < hash_val.length(); i += 2) {
        int byte = std::stoi(hash_val.substr(i, 2), nullptr, 16) ^ key[i % key.length()];
        cipher_text += std::hex << std::setw(2) << std::setfill('0') << byte;
    }
    return cipher_text;
}

int main() {
    std::string data = "secure_message";
    std::string hash_val = generate_hash(data);
    std::string cipher_text = simulate_cipher(hash_val);
    std::cout << cipher_text << std::endl;
    return 0;
}