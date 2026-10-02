#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char** hash_sequence(int* data, int length) {
    char** result = (char**)malloc(length * sizeof(char*));
    for (int i = 0; i < length; i++) {
        char* item_str = (char*)malloc(33 * sizeof(char));
        sprintf(item_str, "%d", data[i]);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, item_str, strlen(item_str));
        SHA256_Final(hash, &sha256);
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&item_str[j * 2], "%02x", hash[j]);
        }
        result[i] = item_str;
    }
    return result;
}

char** cipher_sequence(char** data, int length, int key) {
    char** result = (char**)malloc(length * sizeof(char*));
    for (int i = 0; i < length; i++) {
        int item_length = strlen(data[i]);
        char* encrypted_item = (char*)malloc((item_length + 1) * sizeof(char));
        for (int j = 0; j < item_length; j++) {
            encrypted_item[j] = (char)((data[i][j] + key) % 256);
        }
        encrypted_item[item_length] = '\0';
        result[i] = encrypted_item;
    }
    return result;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int key = 5;
    int length = sizeof(data) / sizeof(data[0]);
    char** hashed_data = hash_sequence(data, length);
    char** ciphered_data = cipher_sequence(hashed_data, length, key);
    for (int i = 0; i < length; i++) {
        printf("%s\n", ciphered_data[i]);
        free(hashed_data[i]);
        free(ciphered_data[i]);
    }
    free(hashed_data);
    free(ciphered_data);
    return 0;
}