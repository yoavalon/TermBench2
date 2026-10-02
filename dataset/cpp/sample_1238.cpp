#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::string process_data(const std::string& data) {
    unsigned char hashed_data[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hashed_data, &sha256);

    std::vector<char> cipher(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        cipher[i] = data[i] ^ hashed_data[i];
    }

    return std::string(cipher.begin(), cipher.end());
}

int main() {
    std::string data = "Example Data";
    std::string processed = process_data(data);
    std::cout << processed << std::endl;
    return 0;
}