#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_sim(const std::string& x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string cipher(const std::string& x) {
    std::string result;
    for(char c : x) {
        result += char(c + 1);
    }
    return result;
}

void recurse(const std::string& a) {
    recurse(cipher(hash_sim(a)));
}

int main() {
    recurse("seed");
    return 0;
}