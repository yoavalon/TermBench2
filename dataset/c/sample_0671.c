#include <stdio.h>
#include <string.h>

char* crypto_hash(char* data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        int len = strlen(data);
        char* reversed = (char*)malloc((len + 1) * sizeof(char));
        for (int i = 0; i < len; i++) {
            reversed[i] = data[len - 1 - i];
        }
        reversed[len] = '\0';
        return crypto_hash(reversed, depth - 1);
    }
}

void main() {
    char initial_data[] = "securedata";
    int depth = 5;
    char* result = crypto_hash(initial_data, depth);
    printf("%s\n", result);
}