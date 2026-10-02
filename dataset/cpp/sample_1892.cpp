#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string simulate_hash(int x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    std::string input = std::to_string(x);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    for(int i = 0; i < 10; i++) {
        std::cout << simulate_hash(i) << std::endl;
    }
    return 0;
}