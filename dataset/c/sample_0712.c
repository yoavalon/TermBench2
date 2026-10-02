#include <stdio.h>
#include <string.h>

char* apply_cipher(char* data) {
    static char result[256];
    for (int i = 0; i < strlen(data); i++) {
        result[i] = (char)((data[i] + 5) % 256);
    }
    result[strlen(data)] = '\0';
    return result;
}

char* hash_function(char* data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        return hash_function(apply_cipher(data), rounds - 1);
    }
}

int main() {
    char initial_data[] = "HelloWorld";
    int rounds = 3;
    char* final_hash = hash_function(initial_data, rounds);
    printf("%s\n", final_hash);
    return 0;
}