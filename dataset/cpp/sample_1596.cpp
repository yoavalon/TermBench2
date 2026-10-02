#include <iostream>
#include <openssl/sha.h>

void hash_simulator() {
    std::string x = "initial";
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, x.c_str(), x.size());
        SHA256_Final(hash, &sha256);
        x = std::string(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
    }
}

int main() {
    hash_simulator();
    return 0;
}