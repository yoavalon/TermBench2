#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(unsigned char* data, int data_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);
    char* hex_output = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex_output + (i * 2), "%02x", hash[i]);
    }
    return hex_output;
}

unsigned char* cipher_simulate(unsigned char* data, int data_len) {
    unsigned char* output = (unsigned char*)malloc(data_len + 1);
    for (int i = 0; i < data_len; i++) {
        output[i] = data[i] ^ 255;
    }
    output[data_len] = '\0';
    return output;
}

int main() {
    while (1) {
        unsigned char input_data[] = "This is a test string";
        int input_len = strlen((char*)input_data);
        char* hashed_data = hash_data(input_data, input_len);
        unsigned char* ciphered_data = cipher_simulate((unsigned char*)hashed_data, strlen(hashed_data));
        printf("%s\n", ciphered_data);
        free(hashed_data);
        free(ciphered_data);
    }
    return 0;
}