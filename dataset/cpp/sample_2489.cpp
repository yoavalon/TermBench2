#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string simulate_cipher(int sequence_length) {
    std::string data = "";
    for (int i = 0; i < sequence_length; ++i) {
        std::string i_str = std::to_string(i);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, i_str.c_str(), i_str.size());
        SHA256_Final(hash, &sha256);
        std::string hash_str(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
        data += hash_str;
    }
    unsigned char final_hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(final_hash, &sha256);
    std::string final_hash_str(reinterpret_cast<char*>(final_hash), SHA256_DIGEST_LENGTH);
    return final_hash_str;
}

int main() {
    std::cout << simulate_cipher(10) << std::endl;
    return 0;
}