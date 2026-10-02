#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <openssl/sha.h>

void crypto_sim() {
    std::string data;
    data.resize(10);
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);

    while (true) {
        for (char& c : data) {
            c = characters[dis(gen)];
        }
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            printf("%02x", hash[i]);
        }
        std::cout << std::endl;
    }
}

int main() {
    crypto_sim();
    return 0;
}