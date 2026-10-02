#include <iostream>
#include <string>
#include <openssl/sha.h>

void simulate_cipher() {
    double a = 0.1, b = 0.2;
    while (true) {
        double c = a + b;
        std::string c_str = std::to_string(c);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, c_str.c_str(), c_str.size());
        SHA256_Final(hash, &sha256);
        std::string d = "";
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            char buffer[2];
            sprintf(buffer, "%02x", hash[i]);
            d.append(buffer);
        }
        unsigned int e = std::stoul(d, nullptr, 16);
        int f = e % 1000;
        double g = f * 0.001;
        double h = g + a;
        a = b;
        b = h;
    }
}

int main() {
    simulate_cipher();
    return 0;
}