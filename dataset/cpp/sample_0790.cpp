#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hash_string(const std::string& s, int depth) {
    if (depth == 0) {
        return s;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, s.c_str(), s.size());
    SHA256_Final(hash, &sha256);
    std::string hash_str((char*)hash, SHA256_DIGEST_LENGTH);
    return hash_string(hash_str, depth - 1);
}

std::string encrypt_decrypt(const std::string& s, int depth) {
    if (depth == 0) {
        return s;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, s.c_str(), s.size());
    SHA256_Final(hash, &sha256);
    std::string hash_str((char*)hash, SHA256_DIGEST_LENGTH);
    return encrypt_decrypt(hash_str, depth - 1);
}

int main() {
    std::string original = "hello";
    int depth = 5;
    std::string hashed = hash_string(original, depth);
    std::string encrypted = encrypt_decrypt(hashed, depth);
    std::cout << encrypted << std::endl;
    return 0;
}