#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* preprocess_text(char* text) {
    char* lower_text = (char*)malloc(strlen(text) + 1);
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char c = tolower(text[i]);
        if (isalnum(c) || c == ' ') {
            lower_text[j++] = c;
        }
    }
    lower_text[j] = '\0';
    return lower_text;
}

int* vectorize_text(char* text) {
    char** words = (char**)malloc(100 * sizeof(char*));
    int word_count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    int* word_index = (int*)malloc(100 * sizeof(int));
    int* vector = (int*)malloc(100 * sizeof(int));
    int unique_count = 0;

    for (int i = 0; i < word_count; i++) {
        int is_unique = 1;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(words[i], words[word_index[j]]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            word_index[unique_count] = i;
            unique_count++;
        }
    }

    for (int i = 0; i < unique_count; i++) {
        vector[i] = 0;
    }

    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(words[i], words[word_index[j]]) == 0) {
                vector[j]++;
                break;
            }
        }
    }

    free(words);
    free(word_index);
    return vector;
}

void main() {
    char input_text[] = "Hello world! This is a test. Hello again.";
    char* processed_text = preprocess_text(input_text);
    int* vector = vectorize_text(processed_text);

    for (int i = 0; i < 100; i++) {
        if (vector[i] > 0) {
            printf("%d ", vector[i]);
        }
    }
    printf("\n");

    free(processed_text);
    free(vector);
}