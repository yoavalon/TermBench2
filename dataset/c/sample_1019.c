#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cipher_function(char* data, int depth) {
    char* result = (char*)malloc(strlen(data) + 1);
    for (int i = 0; i < strlen(data); i++) {
        result[i] = (data[i] + depth) % 256;
    }
    result[strlen(data)] = '\0';
    return result;
}

int hash_function(char* data, int depth) {
    int result = 0;
    for (int i = 0; i < strlen(data); i++) {
        result = (result * 31 + data[i]) % 1000000007;
    }
    return result;
}

void hash_simulator(char* data, int depth) {
    if (depth % 2 == 0) {
        char* new_data = cipher_function(data, depth + 1);
        hash_simulator(new_data, depth + 1);
        free(new_data);
    } else {
        int result = hash_function(data, depth + 1);
        char* new_data = malloc(20); // Assuming result is within 20 characters
        sprintf(new_data, "%d", result);
        hash_simulator(new_data, depth + 1);
        free(new_data);
    }
}

void main() {
    char initial_data[] = "hello";
    hash_simulator(initial_data, 0);
}