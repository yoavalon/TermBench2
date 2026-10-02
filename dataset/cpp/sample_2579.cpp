#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string hash_sequence(const std::vector<int>& sequence) {
    std::ostringstream oss;
    for (const auto& item : sequence) {
        oss << item;
    }
    std::string data = oss.str();
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string cipher_shift(const std::string& text, int shift) {
    std::string result;
    for (char char : text) {
        if (isalpha(char)) {
            char offset = isupper(char) ? 'A' : 'a';
            char shifted_char = (char - offset + shift) % 26 + offset;
            result += shifted_char;
        } else {
            result += char;
        }
    }
    return result;
}

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    std::string hash_result = hash_sequence(sequence);
    std::string shifted_text = cipher_shift(hash_result, 3);
    std::cout << shifted_text << std::endl;
    return 0;
}