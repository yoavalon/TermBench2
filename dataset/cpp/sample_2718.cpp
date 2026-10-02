#include <iostream>
#include <string>
#include <openssl/sha.h>

void crypto_simulator() {
    int a = 0, b = 1;
    while (true) {
        std::string data = std::to_string(a) + std::to_string(b);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::string hex_dig = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buffer[3];
            sprintf(buffer, "%02x", hash[i]);
            hex_dig += buffer;
        }
        a = b;
        b = std::stoi(hex_dig.substr(0, 16), nullptr, 16);
    }
}

int main() {
    crypto_simulator();
    return 0;
}