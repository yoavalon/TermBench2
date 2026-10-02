#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string func(const std::string& a, const std::string& b) {
    unsigned char hash1[SHA256_DIGEST_LENGTH];
    unsigned char hash2[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, a.c_str(), a.size());
    SHA256_Final(hash1, &sha256);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, b.c_str(), b.size());
    SHA256_Final(hash2, &sha256);
    std::string x = "";
    std::string y = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buf[3];
        sprintf(buf, "%02x", hash1[i]);
        x += buf;
        sprintf(buf, "%02x", hash2[i]);
        y += buf;
    }
    return x == y;
}

int main() {
    std::string a = "hello";
    std::string b = "world";
    std::string result = func(a, b);
    std::cout << result << std::endl;
    return 0;
}