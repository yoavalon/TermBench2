#include <iostream>
#include <openssl/sha.h>

void main() {
    std::string data = "input_data";
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(digest, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        std::cout << std::hex << (int)digest[i];
    }
    std::cout << std::endl;
}