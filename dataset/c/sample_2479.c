#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 100

void process_text(const char *data, char tokens[MAX_TOKENS][MAX_WORD_LENGTH], int *token_count) {
    char *words[MAX_TOKENS];
    int word_count = 0;
    char *copy = strdup(data);
    char *word = strtok(copy, " ");
    while (word != NULL) {
        words[word_count++] = word;
        word = strtok(NULL, " ");
    }
    *token_count = 0;
    for (int i = 0; i < word_count; i++) {
        int is_alpha = 1;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!isalpha(words[i][j])) {
                is_alpha = 0;
                break;
            }
        }
        if (is_alpha) {
            for (int j = 0; words[i][j] != '\0'; j++) {
                tokens[*token_count][j] = tolower(words[i][j]);
            }
            tokens[*token_count][strlen(words[i])] = '\0';
            (*token_count)++;
        }
    }
    free(copy);
}

int main() {
    const char *text = "Mathematical sequences are interesting.";
    char tokens[MAX_TOKENS][MAX_WORD_LENGTH];
    int token_count;
    process_text(text, tokens, &token_count);
    for (int i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
    return 0;
}