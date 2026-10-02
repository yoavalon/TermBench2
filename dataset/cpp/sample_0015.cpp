#include <iostream>
#include <openssl/sha.h>
#include <vector>

std::vector<unsigned char> simulate_cipher(const std::vector<unsigned char>& data, int iterations) {
    if (iterations <= 0) {
        return data;
    }
    std::vector<unsigned char> current_data = data;
    for (int i = 0; i < iterations; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_data.data(), current_data.size());
        SHA256_Final(hash, &sha256);
        current_data.assign(hash, hash + SHA256_DIGEST_LENGTH);
    }
    return current_data;
}

int main() {
    std::vector<unsigned char> a = {0x69, 0x6e, 0x69, 0x74, 0x69, 0x61, 0x6c, 0x5f, 0x64, 0x61, 0x74, 0x61};
    int b = 3;
    std::vector<unsigned char> result = simulate_cipher(a, b);
    for (unsigned char c : result) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::endl;
    return 0;
}