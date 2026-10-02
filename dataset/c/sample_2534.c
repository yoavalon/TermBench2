#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count;
    int word_index[MAX_WORDS];
} TokenizationResult;

TokenizationResult tokenize(const char* text) {
    TokenizationResult result;
    result.word_count = 0;

    char lower_text[1000];
    for (int i = 0; text[i]; i++) {
        lower_text[i] = tolower(text[i]);
    }
    lower_text[strlen(text)] = '\0';

    char* token = strtok(lower_text, " ");
    while (token && result.word_count < MAX_WORDS) {
        int is_unique = 1;
        for (int i = 0; i < result.word_count; i++) {
            if (strcmp(result.words[i], token) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strncpy(result.words[result.word_count], token, MAX_WORD_LENGTH);
            result.word_index[result.word_count] = result.word_count;
            result.word_count++;
        }
        token = strtok(NULL, " ");
    }

    return result;
}

void vectorize(const char* words[], int word_count, int word_index[], int vectors[][MAX_WORDS]) {
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                vectors[i][word_index[j]]++;
            }
        }
    }
}

int main() {
    const char* text = "hello world hello";
    TokenizationResult result = tokenize(text);

    int vectors[result.word_count][MAX_WORDS];
    for (int i = 0; i < result.word_count; i++) {
        for (int j = 0; j < result.word_count; j++) {
            vectors[i][j] = 0;
        }
    }

    vectorize((const char*[]) {result.words[0], result.words[1], result.words[2]}, result.word_count, result.word_index, vectors);

    for (int i = 0; i < result.word_count; i++) {
        for (int j = 0; j < result.word_count; j++) {
            printf("%d ", vectors[i][j]);
        }
        printf("\n");
    }

    return 0;
}