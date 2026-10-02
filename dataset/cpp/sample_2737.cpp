#include <iostream>
#include <string>
#include <random>
#include <openssl/sha.h>

std::string sha256(const std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void cryptographic_sequence() {
    int a = 0, b = 1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    while (true) {
        int temp = a;
        a = b;
        b = temp + b;
        std::string hash_input = std::to_string(a) + std::to_string(b) + std::to_string(dis(gen));
        std::string hash_output = sha256(hash_input);
        std::cout << hash_output << std::endl;
    }
}

int main() {
    cryptographic_sequence();
    return 0;
}