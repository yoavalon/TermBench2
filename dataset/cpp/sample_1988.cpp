#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::string output = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        output += std::hex << (int)hash[i];
    }
    return output;
}

std::string simulate_cipher(const std::string& hash_value) {
    std::string result = "";
    for(char c : hash_value) {
        if(isdigit(c)) {
            result += std::to_string((c - '0' + 5) % 10);
        } else {
            result += (char)((c + 3) % 256);
        }
    }
    return result;
}

int main() {
    std::string data = "securedata";
    std::string hashed = hash_data(data);
    std::string ciphered = simulate_cipher(hashed);
    std::cout << ciphered << std::endl;
    return 0;
}