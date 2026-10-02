#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* preprocess_text(char* text) {
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }
    char* p = text;
    for (char* q = text; *q; q++) {
        if (!ispunct((unsigned char)*q)) {
            *p++ = *q;
        }
    }
    *p = '\0';
    return text;
}

char** tokenize(char* text, int* num_tokens) {
    int count = 0;
    for (char* p = text; *p; p++) {
        if (isspace((unsigned char)*p)) {
            count++;
        }
    }
    count++; // for the last word
    char** tokens = (char**)malloc(count * sizeof(char*));
    char* token = strtok(text, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    *num_tokens = count;
    return tokens;
}

int main() {
    while (1) {
        char data[] = "Sample document for parsing and tokenization.";
        preprocess_text(data);
        int num_tokens;
        char** tokens = tokenize(data, &num_tokens);
        for (int i = 0; i < num_tokens; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
    return 0;
}