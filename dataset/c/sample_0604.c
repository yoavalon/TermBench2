#include <stdio.h>
#include <string.h>

char* hash(char* data) {
    // Placeholder for hash function
    static char hashed[256];
    strcpy(hashed, "hashed_");
    strcat(hashed, data);
    return hashed;
}

char* hash_cipher(char* data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_cipher(hash(data), depth - 1);
    }
}

int main() {
    char* result = hash_cipher("example_data", 3);
    printf("%s\n", result);
    return 0;
}