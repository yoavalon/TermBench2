#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* process_text(char* text, int depth, int max_depth) {
    if (depth >= max_depth) {
        return text;
    }
    char** words = (char**)malloc(100 * sizeof(char*));
    int word_count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        words[word_count] = (char*)malloc(100 * sizeof(char));
        for (int i = 0; token[i]; i++) {
            words[word_count][i] = tolower(token[i]);
        }
        word_count++;
        token = strtok(NULL, " ");
    }
    char* result = (char*)malloc(1000 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < word_count; i++) {
        strcat(result, words[i]);
        strcat(result, " ");
        free(words[i]);
    }
    free(words);
    strcat(result, process_text(text, depth + 1, max_depth));
    return result;
}

int main() {
    char input_text[] = "Hello World! This is a Test.";
    char* result = process_text(input_text, 0, 5);
    printf("%s\n", result);
    free(result);
    return 0;
}