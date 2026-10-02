#include <stdio.h>
#include <string.h>

char* hash_recursive(char* data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        static char processed[256];
        for (int i = 0; i < strlen(data); i++) {
            processed[i] = (data[i] + 1) % 256;
        }
        processed[strlen(data)] = '\0';
        return hash_recursive(processed, rounds - 1);
    }
}

char* cipher(char* data, char* key) {
    static char result[256];
    for (int i = 0; i < strlen(data); i++) {
        result[i] = (data[i] + key[i % strlen(key)]) % 256;
    }
    result[strlen(data)] = '\0';
    return result;
}

int main() {
    char initial_data[] = "HelloWorld";
    char key[] = "secret";
    char* hashed_data = hash_recursive(initial_data, 5);
    char* encrypted_data = cipher(hashed_data, key);
    printf("%s\n", encrypted_data);
    return 0;
}