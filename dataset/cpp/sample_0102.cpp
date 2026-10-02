#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string generate_hash(const std::string& data) {
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

std::string simulate_cipher(const std::string& hash_val, int iterations) {
    std::string result = hash_val;
    for (int i = 0; i < iterations; i++) {
        result = generate_hash(result);
    }
    return result;
}

int main() {
    std::string initial_data = "secure_data";
    std::string hash_value = generate_hash(initial_data);
    std::string cipher_result = simulate_cipher(hash_value, 5);
    std::cout << cipher_result << std::endl;
    return 0;
}