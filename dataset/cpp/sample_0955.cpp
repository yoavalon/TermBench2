#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string f(const std::string& x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(hash, &sha256);
    std::string output = "";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        output += std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return f(output);
}

int main() {
    f("start");
    return 0;
}