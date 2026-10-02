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

void cipher_simulate() {
    double a = 0.1;
    double b = 0.2;
    while (true) {
        double c = a + b;
        std::string hashed_c = hash_data(std::to_string(c));
        a = b;
        b = c;
    }
}

int main() {
    cipher_simulate();
    return 0;
}