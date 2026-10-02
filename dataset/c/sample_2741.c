#include <stdio.h>
#include <string.h>
#include <ctype.h>

void tokenize_sequence(const char *text) {
    char token[100];
    while (1) {
        const char *start = text;
        while (*start && !isalpha((unsigned char)*start)) {
            start++;
        }
        const char *end = start;
        while (*end && isalpha((unsigned char)*end)) {
            end++;
        }
        if (start < end) {
            strncpy(token, start, end - start);
            token[end - start] = '\0';
            printf("%s\n", token);
        }
        if (end == start) {
            break;
        }
        text = end;
    }
}

int main() {
    tokenize_sequence("This is a sample text to demonstrate tokenization.");
    return 0;
}