#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int* process_sequence(int* data, int length) {
    int* result = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        char str[33];
        sprintf(str, "%d", data[i]);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str, strlen(str));
        SHA256_Final(hash, &sha256);
        unsigned long long int_value = 0;
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            int_value = (int_value << 8) | hash[j];
        }
        result[i] = int_value % 1000;
    }
    return result;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int* result = process_sequence(data, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}