#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** parse_document(char* text, int* num_sentences) {
    regex_t regex;
    regcomp(&regex, "[.!?]", REG_EXTENDED);
    regmatch_t pmatch[1];
    char* temp = strdup(text);
    char* sentence;
    int count = 0;

    sentence = strtok(temp, ".!?");
    while (sentence != NULL) {
        count++;
        sentence = strtok(NULL, ".!?");
    }

    char** sentences = malloc(count * sizeof(char*));
    count = 0;
    sentence = strtok(text, ".!?");
    while (sentence != NULL) {
        sentences[count++] = strdup(sentence);
        sentence = strtok(NULL, ".!?");
    }

    *num_sentences = count;
    regfree(&regex);
    free(temp);
    return sentences;
}

char** tokenize(char** sentences, int num_sentences, int* num_tokens) {
    regex_t regex;
    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    regmatch_t pmatch[1];
    int total_tokens = 0;

    for (int i = 0; i < num_sentences; i++) {
        char* sentence = sentences[i];
        char* word = strtok(sentence, " ");
        while (word != NULL) {
            if (regexec(&regex, word, 1, pmatch, 0) == 0) {
                total_tokens++;
            }
            word = strtok(NULL, " ");
        }
    }

    char** tokens = malloc(total_tokens * sizeof(char*));
    total_tokens = 0;
    for (int i = 0; i < num_sentences; i++) {
        char* sentence = sentences[i];
        char* word = strtok(sentence, " ");
        while (word != NULL) {
            if (regexec(&regex, word, 1, pmatch, 0) == 0) {
                tokens[total_tokens++] = strdup(word);
            }
            word = strtok(NULL, " ");
        }
    }

    *num_tokens = total_tokens;
    regfree(&regex);
    return tokens;
}

void free_sentences(char** sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
}

void free_tokens(char** tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main() {
    char* document = "This is a sample document. It contains several sentences! Each sentence is a tokenized unit.";
    int num_sentences;
    char** sentences = parse_document(document, &num_sentences);
    int num_tokens;
    char** tokens = tokenize(sentences, num_sentences, &num_tokens);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    free_sentences(sentences, num_sentences);
    free_tokens(tokens, num_tokens);
    return 0;
}