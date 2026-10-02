#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>

std::string process(const std::string& data) {
    unsigned char message[SHA256_DIGEST_LENGTH];
    for (int i = 0; i < 100; ++i) {
        unsigned char key[SHA256_DIGEST_LENGTH];
        std::string i_str = std::to_string(i);
        SHA256((unsigned char*)i_str.c_str(), i_str.size(), key);
        HMAC(EVP_sha256(), key, SHA256_DIGEST_LENGTH, (unsigned char*)data.c_str(), data.size(), message, NULL);
    }
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)message[i];
    }
    return ss.str();
}

int main() {
    std::string result = process("securedata");
    std::cout << result << std::endl;
    return 0;
}