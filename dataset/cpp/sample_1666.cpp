#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include <cstring>

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

std::string cipher_simulate(const std::string& data) {
    std::string output;
    for (char byte : data) {
        output += (char)(byte ^ 255);
    }
    return output;
}

int main() {
    while (true) {
        std::string input_data = "This is a test string";
        std::string hashed_data = hash_data(input_data);
        std::string ciphered_data = cipher_simulate(hashed_data);
        std::cout << ciphered_data << std::endl;
    }
    return 0;
}