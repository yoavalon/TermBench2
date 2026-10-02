#include <iostream>
#include <openssl/sha.h>
#include <vector>

std::vector<unsigned char> process_data(const std::vector<unsigned char>& data, int rounds = 10) {
    std::vector<unsigned char> result = data;
    for (int i = 0; i < rounds; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, result.data(), result.size());
        SHA256_Final(hash, &sha256);
        result.assign(hash, hash + SHA256_DIGEST_LENGTH);
    }
    return result;
}

int main() {
    std::vector<unsigned char> data = {0x69, 0x6e, 0x69, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x64, 0x61, 0x74, 0x61};
    std::vector<unsigned char> final_result = process_data(data);
    for (unsigned char c : final_result) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::endl;
    return 0;
}