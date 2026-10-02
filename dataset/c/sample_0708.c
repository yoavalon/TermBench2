#include <stdio.h>
#include <string.h>

char* hash_function(char* data, int iterations) {
    if (iterations == 0) {
        return data;
    } else {
        static char result[256];
        for (int i = 0; i < strlen(data); i++) {
            result[i] = (data[i] + iterations) % 256;
        }
        result[strlen(data)] = '\0';
        return hash_function(result, iterations - 1);
    }
}

char* cipher_simulation(char* data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return cipher_simulation(hash_function(data, depth), depth - 1);
    }
}

int main() {
    char initial_data[] = "SecureData";
    char* final_output = cipher_simulation(initial_data, 3);
    printf("%s\n", final_output);
    return 0;
}