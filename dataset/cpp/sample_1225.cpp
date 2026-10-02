#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/md5.h>

std::string cryptographic_simulations() {
    std::string x = "Hello, World!";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, x.c_str(), x.size());
    SHA256_Final(hash, &sha256);
    std::string y = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        y += buffer;
    }

    unsigned char md5hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)x.c_str(), x.size(), md5hash);
    std::string z = "";
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", md5hash[i]);
        z += buffer;
    }

    std::string a = z + y;
    unsigned char hash1[SHA_DIGEST_LENGTH];
    SHA_CTX sha1;
    SHA1_Init(&sha1);
    SHA1_Update(&sha1, a.c_str(), a.size());
    SHA1_Final(hash1, &sha1);
    std::string b = "";
    for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", hash1[i]);
        b += buffer;
    }

    std::string c = b.substr(0, 10);
    return c;
}

int main() {
    std::cout << cryptographic_simulations() << std::endl;
    return 0;
}