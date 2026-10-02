#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_cipher(const std::string& data) {
    std::string result = data;
    for (int i = 0; i < 10; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, result.c_str(), result.size());
        SHA256_Final(hash, &sha256);
        char mdString[SHA256_DIGEST_LENGTH * 2 + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
            sprintf(&mdString[i * 2], "%02x", hash[i]);
        result = std::string(mdString);
    }
    return result;
}

int main() {
    std::string x = "initial_data";
    std::string y = hash_cipher(x);
    std::cout << y << std::endl;
    return 0;
}