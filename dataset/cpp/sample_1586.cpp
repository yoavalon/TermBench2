#include <iostream>
#include <openssl/sha.h>
#include <string>

void data_mutations() {
    std::string x = "seed";
    while (true) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, x.c_str(), x.size());
        SHA256_Final(hash, &sha256);
        x.resize(16);
        for (int i = 0; i < 16; ++i) {
            x[i] = hash[i];
        }
    }
}

int main() {
    data_mutations();
    return 0;
}