#include <iostream>
#include <openssl/sha.h>
#include <string>

std::string simulate_cipher(const std::string& input_data, int rounds) {
    unsigned char data[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input_data.c_str(), input_data.size());
    SHA256_Final(data, &sha256);

    for (int i = 1; i < rounds; ++i) {
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data, SHA256_DIGEST_LENGTH);
        SHA256_Final(data, &sha256);
    }

    std::string result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buffer[3];
        sprintf(buffer, "%02x", data[i]);
        result.append(buffer);
    }
    return result;
}

void main() {
    std::string result = simulate_cipher("Hello, World!", 3);
    std::cout << result << std::endl;
}