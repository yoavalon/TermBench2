#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_cipher_simulation(const std::string& data) {
    std::string result = data;
    for (int i = 0; i < 3; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, result.c_str(), result.size());
        SHA256_Final(hash, &sha256);
        result = "";
        for (int j = 0; j < SHA256_DIGEST_LENGTH; ++j) {
            result += std::to_string((int)hash[j]);
        }
    }
    return result;
}

int main() {
    std::string result = hash_cipher_simulation("initial_data");
    std::cout << result << std::endl;
    return 0;
}