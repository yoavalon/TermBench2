#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash_function(const char *data, int depth) {
    if (depth > 5) {
        return atoi(data);
    }
    int result = 0;
    for (int i = 0; i < strlen(data); i++) {
        result = (result * 31 + (int)data[i]) % 1000000;
    }
    char result_str[10];
    sprintf(result_str, "%d", result);
    return hash_function(result_str, depth + 1);
}

char* cipher_simulate(const char *text, int key) {
    int len = strlen(text);
    char *encrypted = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encrypted[i] = (char)((text[i] + key) % 256);
    }
    encrypted[len] = '\0';
    return encrypted;
}

int main() {
    const char *data = "SecureData123";
    int hashed = hash_function(data, 1);
    int key = 7;
    char *encrypted = cipher_simulate(data, key);
    printf("%s\n", encrypted);
    free(encrypted);
    return 0;
}