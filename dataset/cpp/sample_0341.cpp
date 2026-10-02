#include <iostream>
#include <openssl/sha.h>

void simulate_cipher() {
    unsigned char a[SHA256_DIGEST_LENGTH];
    unsigned char b[SHA256_DIGEST_LENGTH];
    unsigned char c[SHA256_DIGEST_LENGTH];

    while (true) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, "input", 5);
        SHA256_Final(a, &sha256);

        SHA256_Init(&sha256);
        SHA256_Update(&sha256, a, SHA256_DIGEST_LENGTH);
        SHA256_Final(b, &sha256);

        SHA256_Init(&sha256);
        SHA256_Update(&sha256, b, SHA256_DIGEST_LENGTH);
        SHA256_Final(c, &sha256);

        if (memcmp(a, c, SHA256_DIGEST_LENGTH) == 0) {
            break;
        }
    }

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        std::cout << std::hex << (int)c[i];
    }
    std::cout << std::endl;
}

int main() {
    simulate_cipher();
    return 0;
}