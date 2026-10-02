#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::vector<std::string> hash_sequence(const std::vector<int>& data) {
    std::vector<std::string> result;
    for (const auto& item : data) {
        std::string str_item = std::to_string(item);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str_item.c_str(), str_item.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        result.push_back(ss.str());
    }
    return result;
}

std::vector<std::string> cipher_sequence(const std::vector<std::string>& data, int key) {
    std::vector<std::string> result;
    for (const auto& item : data) {
        std::string encrypted_item;
        for (char char : item) {
            encrypted_item += char + key;
        }
        result.push_back(encrypted_item);
    }
    return result;
}

void main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    int key = 5;
    std::vector<std::string> hashed_data = hash_sequence(data);
    std::vector<std::string> ciphered_data = cipher_sequence(hashed_data, key);
    for (const auto& item : ciphered_data) {
        std::cout << item << std::endl;
    }
}

int main() {
    main();
    return 0;
}