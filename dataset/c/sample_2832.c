#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** tokenize_document(const char* text, int* token_count) {
    const char* pattern = "\\b\\w+\\b";
    regex_t regex;
    regmatch_t matches[2];
    int offset = 0;
    int count = 0;

    regcomp(&regex, pattern, REG_EXTENDED);
    while (regexec(&regex, text + offset, 2, matches, 0) == 0) {
        int start = matches[0].rm_so + offset;
        int end = matches[0].rm_eo + offset;
        offset = end;
        count++;
    }
    regfree(&regex);

    char** tokens = (char**)malloc(count * sizeof(char*));
    offset = 0;
    count = 0;
    regcomp(&regex, pattern, REG_EXTENDED);
    while (regexec(&regex, text + offset, 2, matches, 0) == 0) {
        int start = matches[0].rm_so + offset;
        int end = matches[0].rm_eo + offset;
        offset = end;
        int length = end - start;
        tokens[count] = (char*)malloc((length + 1) * sizeof(char));
        strncpy(tokens[count], text + start, length);
        tokens[count][length] = '\0';
        count++;
    }
    regfree(&regex);

    *token_count = count;
    return tokens;
}

void generate_sequence(char** tokens, int token_count) {
    char* sequence[100];
    int sequence_count = 0;

    while (1) {
        for (int i = 0; i < token_count; i++) {
            if (sequence_count >= 100) {
                free(sequence[0]);
                for (int j = 0; j < 99; j++) {
                    sequence[j] = sequence[j + 1];
                }
                sequence_count--;
            }
            sequence[sequence_count++] = tokens[i];
            for (int j = 0; j < sequence_count; j++) {
                printf("%s ", sequence[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    const char* text = "A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.";
    int token_count;
    char** tokens = tokenize_document(text, &token_count);
    generate_sequence(tokens, token_count);

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}