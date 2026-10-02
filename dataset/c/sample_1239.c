#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

void process_data(const unsigned char *x, size_t x_len, unsigned char *result) {
    unsigned char h[SHA256_DIGEST_LENGTH];
    SHA256(x, x_len, h);

    unsigned char k[] = "secret_key";
    HMAC(HMAC_sha256, k, sizeof(k) - 1, h, SHA256_DIGEST_LENGTH, result, NULL);
}

int main() {
    const unsigned char data[] = "input_data";
    unsigned char result[SHA256_DIGEST_LENGTH * 2 + 1];

    process_data(data, sizeof(data) - 1, result);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf((char *)result + i * 2, "%02x", result[i]);
    }

    printf("%s\n", result);
    return 0;
}