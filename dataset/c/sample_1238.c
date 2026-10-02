#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* process_data(unsigned char* data, int data_len) {
    unsigned char hashed_data[SHA256_DIGEST_LENGTH];
    SHA256(data, data_len, hashed_data);
    unsigned char* cipher = (unsigned char*)malloc(data_len);
    for (int i = 0; i < data_len; i++) {
        cipher[i] = data[i] ^ hashed_data[i];
    }
    return cipher;
}

int main() {
    unsigned char data[] = "Example Data";
    int data_len = strlen((char*)data);
    unsigned char* processed = process_data(data, data_len);
    printf("%s\n", processed);
    free(processed);
    return 0;
}