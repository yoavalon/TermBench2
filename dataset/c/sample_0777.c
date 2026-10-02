#include <stdio.h>
#include <string.h>

char* hash_function(char* data, int n) {
    if (n == 0) {
        return data;
    }
    static char result[256];
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        result[i] = (data[i] + 1) % 256;
    }
    result[len] = '\0';
    return hash_function(result, n - 1);
}

char* cipher(char* data, int n) {
    if (n == 0) {
        return data;
    }
    static char temp[256];
    strcpy(temp, hash_function(data, 1));
    return cipher(temp, n - 1);
}

int main() {
    char original_data[] = "HelloWorld";
    int iterations = 5;
    char* encrypted_data = cipher(original_data, iterations);
    printf("%s\n", encrypted_data);
    return 0;
}