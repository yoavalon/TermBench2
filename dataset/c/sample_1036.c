#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

char** tokenize_text(const char* text, int* word_count) {
    char* text_copy = strdup(text);
    char* token = strtok(text_copy, " \t\n\r");
    char** words = malloc(MAX_WORDS * sizeof(char*));
    *word_count = 0;

    while (token != NULL) {
        int i = 0;
        while (token[i] && !isalpha(token[i])) i++;
        if (i < strlen(token)) {
            words[*word_count] = strdup(token + i);
            (*word_count)++;
        }
        token = strtok(NULL, " \t\n\r");
    }

    free(text_copy);
    return words;
}

void vectorize(char** word_list, int word_count, int* vector, int vocab_size) {
    int* word_counts = calloc(vocab_size, sizeof(int));
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < vocab_size; j++) {
            if (strcmp(word_list[i], word_list[j]) == 0) {
                word_counts[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < vocab_size; i++) {
        vector[i] = word_counts[i];
    }

    free(word_counts);
}

void recursive_vectorize(const char* text) {
    int word_count;
    char** words = tokenize_text(text, &word_count);
    int* vector = calloc(word_count, sizeof(int));
    vectorize(words, word_count, vector, word_count);
    recursive_vectorize(text);

    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);
    free(vector);
}

int main() {
    const char* sample_text = "Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.";
    recursive_vectorize(sample_text);
    return 0;
}