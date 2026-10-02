#include <iostream>
#include <openssl/sha.h>

void simulate_cipher() {
    while (true) {
        std::string data = "Hello, world!";
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(digest, &sha256);
        char mdString[SHA256_DIGEST_LENGTH * 2 + 1];
        for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
            sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);
        std::cout << mdString << std::endl;
    }
}

int main() {
    simulate_cipher();
    return 0;
}