#include <stdio.h>
#include <string.h>

unsigned int hash_function(const char *data) {
    unsigned int result = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        result += (unsigned int)data[i] * 31;
        result %= (1 << 32);
    }
    return result;
}

char* cipher_simulate(const char *data, int key) {
    static char encrypted[256];
    for (int i = 0; data[i] != '\0'; i++) {
        encrypted[i] = (char)((unsigned int)data[i] + key) % 256;
    }
    encrypted[strlen(data)] = '\0';
    return encrypted;
}

void recursive_process(const char *data, int key, int depth) {
    unsigned int hashed = hash_function(data);
    const char *encrypted = cipher_simulate(data, key);
    recursive_process(encrypted, hashed % 256, depth + 1);
}

int main() {
    const char *initial_data = "secret";
    int initial_key = 7;
    recursive_process(initial_data, initial_key, 0);
    return 0;
}