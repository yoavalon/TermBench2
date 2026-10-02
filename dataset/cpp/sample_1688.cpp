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

std::string cipher_simulate(const std::string& key, const std::string& data) {
    std::string result = "";
    for (size_t i = 0; i < data.length(); ++i) {
        char ch = data[i];
        int shift = (key[i % key.length()] % 26);
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result += (char)(((ch - base + shift) % 26) + base);
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    while (true) {
        std::string key = "secretkey";
        std::string data = hash_data("sensitiveinfo");
        std::string encrypted = cipher_simulate(key, data);
        std::cout << encrypted << std::endl;
    }
    return 0;
}