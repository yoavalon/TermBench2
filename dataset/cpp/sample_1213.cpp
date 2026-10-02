#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string hash_and_cipher(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    std::string hash_digest = ss.str();

    std::string cipher_text;
    for (char c : hash_digest) {
        cipher_text += (char)((c + 3) % 256);
    }
    return cipher_text;
}

int main() {
    std::string data = "sensitive information";
    std::string result = hash_and_cipher(data);
    std::cout << result << std::endl;
    return 0;
}