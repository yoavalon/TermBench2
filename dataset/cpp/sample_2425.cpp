#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::vector<std::string> simulate_cipher(int n) {
    int x = 0;
    std::vector<std::string> result;
    while (x < n) {
        std::stringstream ss;
        ss << x;
        std::string input = ss.str();
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, input.c_str(), input.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss2;
        for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss2 << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        result.push_back(ss2.str());
        x++;
    }
    return result;
}

int main() {
    simulate_cipher(10);
    return 0;
}