#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_recursive(const std::string& data, const std::string& salt, double rounds) {
    if (rounds > 0) {
        std::string combined = data + salt;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, combined.c_str(), combined.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return hash_recursive(ss.str(), salt, rounds - 1);
    }
    return data;
}

int main() {
    hash_recursive("data", "salt", std::numeric_limits<double>::infinity());
    return 0;
}