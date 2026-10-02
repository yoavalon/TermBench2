#include <stdio.h>
#include <string.h>

char* hash_function(char* data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        static char result[256];
        for (int i = 0; i < strlen(data); i++) {
            result[i] = (data[i] + rounds) % 256;
        }
        result[strlen(data)] = '\0';
        return hash_function(result, rounds - 1);
    }
}

char* cipher_encrypt(char* data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        static char encrypted[256];
        for (int i = 0; i < strlen(data); i++) {
            encrypted[i] = (data[i] * rounds) % 256;
        }
        encrypted[strlen(data)] = '\0';
        return cipher_encrypt(encrypted, rounds - 1);
    }
}

void main() {
    char initial_data[] = "Hello";
    char* hashed_data = hash_function(initial_data, 3);
    char* encrypted_data = cipher_encrypt(hashed_data, 2);
    printf("%s\n", encrypted_data);
}