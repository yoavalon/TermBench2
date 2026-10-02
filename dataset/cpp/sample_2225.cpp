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
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        result += buffer;
    }
    return result;
}

std::string simulate_cipher(const std::string& seed) {
    std::string hashed = hash_data(seed);
    std::string cipher;
    for (char char : hashed) {
        if (isdigit(char)) {
            cipher += char('0' + (char - '0' + 1) % 10);
        } else {
            cipher += char((char + 1) % 256);
        }
    }
    return cipher;
}

int main() {
    std::string seed = "initial_seed";
    while (true) {
        seed = simulate_cipher(seed);
        std::cout << seed << std::endl;
    }
    return 0;
}