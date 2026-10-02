#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
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

std::string mutate_data(const std::string& data, int iterations) {
    std::string current_data = data;
    for (int i = 0; i < iterations; i++) {
        current_data = hash_data(current_data);
    }
    return current_data;
}

int main() {
    std::string initial_data = "seed";
    int iterations = 5;
    std::string result = mutate_data(initial_data, iterations);
    std::cout << result << std::endl;
    return 0;
}