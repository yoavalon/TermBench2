#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_function(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string recursive_cipher(const std::string& data, int count) {
    if (count == 0) {
        return data;
    } else {
        std::string new_data = hash_function(data);
        return recursive_cipher(new_data, count - 1);
    }
}

int main() {
    std::string initial_data = "seed";
    int recursion_count = -1;
    std::string result = recursive_cipher(initial_data, recursion_count);
    std::cout << result << std::endl;
    return 0;
}