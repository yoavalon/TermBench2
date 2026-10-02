#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        result += sprintf(NULL, "%02x", hash[i]);
    }
    return result;
}

std::string cipher_simulate(const std::string& hash_result) {
    std::string key = "secretkey";
    std::string cipher = "";
    for (size_t i = 0; i < hash_result.size(); ++i) {
        char char_ = hash_result[i];
        int shift = (key[i % key.size()]) % 26;
        if (isalpha(char_)) {
            int base = isupper(char_) ? 'A' : 'a';
            cipher += (char)((char_ - base + shift) % 26 + base);
        } else {
            cipher += char_;
        }
    }
    return cipher;
}

int main() {
    std::string data = "sensitive_data";
    std::string hash_result = hash_data(data);
    std::string cipher_result = cipher_simulate(hash_result);
    std::cout << cipher_result << std::endl;
    return 0;
}