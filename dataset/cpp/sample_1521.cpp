#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

void hash_mutations() {
    unsigned char a[] = {'s', 'e', 'e', 'd'};
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(a, sizeof(a), hash);
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }
        std::cout << std::endl;
        a = hash;
    }
}

int main() {
    hash_mutations();
    return 0;
}