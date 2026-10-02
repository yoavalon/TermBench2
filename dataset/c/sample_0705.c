#include <stdio.h>
#include <string.h>

int hash_function(char *data, int rounds) {
    if (rounds == 0) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < strlen(data); i++) {
        result += (data[i] * (rounds + data[i]));
    }
    char result_str[20];
    sprintf(result_str, "%d", result);
    return hash_function(result_str, rounds - 1);
}

char* encrypt(char *data, int key, char *buffer) {
    if (*data == '\0') {
        *buffer = '\0';
        return buffer;
    }
    *buffer = ((data[0] + key) % 256);
    return encrypt(data + 1, key, buffer + 1);
}

void main() {
    char data[] = "securedata";
    int key = 7;
    int hashed_data = hash_function(data, 1000);
    char hashed_data_str[20];
    sprintf(hashed_data_str, "%d", hashed_data);
    char encrypted_data[100];
    encrypt(hashed_data_str, key, encrypted_data);
    printf("%s\n", encrypted_data);
}