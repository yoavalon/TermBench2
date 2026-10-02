#include <iostream>
#include <iomanip>
#include <openssl/sha.h>

void simulate_cipher_sequence(unsigned char* data, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, strlen((char*)data), hash);
        memcpy(data, hash, SHA256_DIGEST_LENGTH);
    }
}

int main() {
    unsigned char initial_data[] = "hello";
    int iterations = 5;
    simulate_cipher_sequence(initial_data, iterations);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        printf("%02x", initial_data[i]);
    }
    std::cout << std::endl;
    return 0;
}