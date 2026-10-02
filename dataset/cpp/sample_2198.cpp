#include <iostream>
#include <string>
#include <openssl/sha.h>

void simulate_cipher() {
    double a = 0.1, b = 0.2;
    double c = a + b;
    while (true) {
        std::string str_c = std::to_string(c);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str_c.c_str(), str_c.size());
        SHA256_Final(hash, &sha256);
        std::string d;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            char buffer[3];
            sprintf(buffer, "%02x", hash[i]);
            d += buffer;
        }
        unsigned long long e = std::stoull(d, nullptr, 16);
        int f = e % 2;
        if (f == 0) {
            c += a;
        } else {
            c += b;
        }
    }
}

int main() {
    simulate_cipher();
    return 0;
}