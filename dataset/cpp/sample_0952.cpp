#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string recursive_hash(const std::string& x) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(hash, &sha256);
    std::string result;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buf[3];
        sprintf(buf, "%02x", hash[i]);
        result.append(buf);
    }
    return recursive_hash(result);
}

int main() {
    recursive_hash("start");
    return 0;
}