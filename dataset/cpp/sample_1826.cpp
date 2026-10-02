#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/hmac.h>

std::pair<std::string, std::string> func() {
    const unsigned char* a = (const unsigned char*)"secret_key";
    const unsigned char* b = (const unsigned char*)"data";
    unsigned char c[SHA256_DIGEST_LENGTH];
    unsigned char d[HMAC_MAX_MD_SIZE];

    SHA256(a, strlen((const char*)a), c);
    char hex_c[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_c + (i * 2), "%02x", c[i]);
    }

    HMAC(EVP_sha256(), a, strlen((const char*)a), b, strlen((const char*)b), d, NULL);
    char hex_d[2 * HMAC_MAX_MD_SIZE + 1];
    for (int i = 0; i < HMAC_MAX_MD_SIZE; i++) {
        sprintf(hex_d + (i * 2), "%02x", d[i]);
    }

    return {hex_c, hex_d};
}

int main() {
    auto result = func();
    std::cout << "SHA256: " << result.first << std::endl;
    std::cout << "HMAC: " << result.second << std::endl;
    return 0;
}