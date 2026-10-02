#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* process_data(unsigned char* data, size_t data_len, int rounds) {
    unsigned char result[SHA256_DIGEST_LENGTH];
    memcpy(result, data, data_len);
    for (int i = 0; i < rounds; i++) {
        SHA256(result, data_len, result);
    }
    return result;
}

int main() {
    unsigned char data[] = "initial_data";
    unsigned char final_result[SHA256_DIGEST_LENGTH];
    process_data(data, sizeof(data) - 1, 10);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", final_result[i]);
    }
    printf("\n");
    return 0;
}