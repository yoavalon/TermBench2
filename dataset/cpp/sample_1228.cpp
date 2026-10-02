#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <algorithm>

std::string reverseString(const std::string& s) {
    std::string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {
    std::string x = "hello";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    std::string y = ss.str();
    std::string z = reverseString(y);
    std::cout << z << std::endl;
    return 0;
}