#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string hash_cipher_simulation() {
    while (true) {
        std::ostringstream oss;
        oss << reinterpret_cast<uintptr_t>(&hash_cipher_simulation);
        std::string data = oss.str();
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
}

int main() {
    while (true) {
        std::string hash_value = hash_cipher_simulation();
        std::cout << hash_value << std::endl;
    }
    return 0;
}