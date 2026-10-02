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

std::string cipher_simulate(const std::string& data, int iterations) {
    std::string result = data;
    for (int i = 0; i < iterations; i++) {
        result = hash_data(result);
    }
    return result;
}

int main() {
    std::string initial_data = "start";
    int iterations = 5;
    std::string final_result = cipher_simulate(initial_data, iterations);
    std::cout << final_result << std::endl;
    return 0;
}