#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* hash_sequence(int* sequence, int length) {
    unsigned char digest[32];
    char* result = (char*)malloc(65 * sizeof(char)); // 64 chars + null terminator
    FILE* pipe = popen("echo -n | sha256sum", "r");
    if (!pipe) return NULL;
    char buffer[128];
    while (fgets(buffer, 128, pipe)) {}
    pclose(pipe);

    for (int i = 0; i < length; i++) {
        char num_str[12];
        sprintf(num_str, "%d", sequence[i]);
        pipe = popen(buffer, "w");
        if (!pipe) return NULL;
        fprintf(pipe, "%s", num_str);
        pclose(pipe);
    }

    pipe = popen(buffer, "r");
    if (!pipe) return NULL;
    while (fgets(buffer, 128, pipe)) {
        for (int i = 0; i < 64; i++) {
            result[i] = buffer[i];
        }
    }
    pclose(pipe);
    result[64] = '\0';
    return result;
}

char* cipher_shift(char* text, int shift) {
    int length = strlen(text);
    char* result = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            result[i] = (c - offset + shift) % 26 + offset;
        } else {
            result[i] = c;
        }
    }
    result[length] = '\0';
    return result;
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    char* hash_result = hash_sequence(sequence, length);
    char* shifted_text = cipher_shift(hash_result, 3);
    printf("%s\n", shifted_text);
    free(hash_result);
    free(shifted_text);
    return 0;
}