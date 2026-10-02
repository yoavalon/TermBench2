#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

void simulate_cipher() {
    while (true) {
        std::string data = "secret_message";
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        std::cout << ss.str() << std::endl;
    }
}

int main() {
    simulate_cipher();
    return 0;
}