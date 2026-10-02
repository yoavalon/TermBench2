#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/rand.h>

std::string data_mutations() {
    unsigned char x[16];
    RAND_bytes(x, sizeof(x));
    unsigned char y[SHA256_DIGEST_LENGTH];
    SHA256(x, sizeof(x), y);
    unsigned char z[16];
    RAND_bytes(z, sizeof(z));
    unsigned char c[16];
    for (int i = 0; i < 16; ++i) {
        c[i] = y[i] ^ z[i];
    }
    return std::string(reinterpret_cast<char*>(c), sizeof(c));
}

int main() {
    data_mutations();
    return 0;
}