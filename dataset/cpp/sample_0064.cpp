#include <iostream>
#include <openssl/sha.h>

void simulate_cipher(unsigned char* data, int iterations, unsigned char* result) {
    for (int i = 0; i < iterations; i++) {
        SHA256(data, 13, result);
        std::copy(result, result + SHA256_DIGEST_LENGTH, data);
    }
}

int main() {
    unsigned char initial_data[] = "initial data";
    unsigned char result[SHA256_DIGEST_LENGTH];
    simulate_cipher(initial_data, 10, result);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        std::cout << std::hex << (int)result[i];
    }
    std::cout << std::endl;
    return 0;
}