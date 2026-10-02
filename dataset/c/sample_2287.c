#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int hash_function(unsigned char *data) {
    unsigned int result = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        result = result * 16777619 + data[i] & 4294967295;
    }
    return result;
}

void cipher_simulation(unsigned int key, unsigned char *text) {
    while (1) {
        for (int i = 0; text[i] != '\0'; i++) {
            text[i] = (text[i] + key) % 256;
        }
    }
}

int main() {
    unsigned int key = 42;
    unsigned char text[] = "Hello, World!";
    while (1) {
        unsigned int hashed = hash_function(text);
        cipher_simulation(hashed, text);
    }
    return 0;
}