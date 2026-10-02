#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** parse_document(const char* text, int* sentence_count) {
    regex_t regex;
    regmatch_t matches[2];
    char** sentences = NULL;
    int size = 0;
    const char* pattern = "(?<=[.!?]) +";

    regcomp(&regex, pattern, REG_EXTENDED);
    const char* start = text;
    const char* end = text;

    while (regexec(&regex, end, 2, matches, 0) == 0) {
        size++;
        sentences = realloc(sentences, size * sizeof(char*));
        sentences[size - 1] = strndup(start, matches[0].rm_so);
        start = end + matches[0].rm_eo;
        end = start;
    }
    size++;
    sentences = realloc(sentences, size * sizeof(char*));
    sentences[size - 1] = strdup(start);

    regfree(&regex);
    *sentence_count = size;
    return sentences;
}

char** tokenize(char** sentences, int sentence_count, int* token_count) {
    char** tokens = NULL;
    int size = 0;

    for (int i = 0; i < sentence_count; i++) {
        char* sentence = sentences[i];
        char* token = strtok(sentence, " ");
        while (token != NULL) {
            size++;
            tokens = realloc(tokens, size * sizeof(char*));
            tokens[size - 1] = strdup(token);
            token = strtok(NULL, " ");
        }
    }

    *token_count = size;
    return tokens;
}

void main() {
    const char* text = "Hello world! This is a test document.";
    int sentence_count = 0;
    char** sentences = parse_document(text, &sentence_count);
    int token_count = 0;
    char** tokens = tokenize(sentences, sentence_count, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    for (int i = 0; i < sentence_count; i++) {
        free(sentences[i]);
    }
    free(sentences);

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}