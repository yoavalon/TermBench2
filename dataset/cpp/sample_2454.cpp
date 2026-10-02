#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::vector<int> process_sequence(const std::vector<int>& data) {
    std::vector<int> result;
    for (size_t i = 0; i < data.size(); ++i) {
        std::string data_str = std::to_string(data[i]);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data_str.c_str(), data_str.size());
        SHA256_Final(hash, &sha256);
        std::string hash_hex;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buffer[3];
            sprintf(buffer, "%02x", hash[i]);
            hash_hex += buffer;
        }
        int hash_int = std::stoi(hash_hex, nullptr, 16);
        result.push_back(hash_int % 1000);
    }
    return result;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result = process_sequence(data);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}