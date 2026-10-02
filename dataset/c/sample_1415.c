#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100
#define STOP_WORDS_COUNT 100

typedef struct {
    char text[1000];
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
} DocumentParser;

typedef struct {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
    char mutated_tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int mutated_token_count;
} DataMutator;

const char* stop_words[STOP_WORDS_COUNT] = {
    "the", "and", "is", "in", "to", "a", "of", "it", "that", "for", "on", "with", "as", "by", "at", "from", "this", "an", "or", "but", "not", "are", "be", "was", "were", "has", "have", "had", "do", "does", "did", "will", "would", "can", "could", "should", "if", "then", "else", "while", "when", "where", "who", "what", "why", "how", "all", "any", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"
};

void DocumentParser_init(DocumentParser* parser, const char* text) {
    strcpy(parser->text, text);
    parser->token_count = 0;
}

void DocumentParser_tokenize(DocumentParser* parser) {
    char* token = strtok(parser->text, " ");
    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        strcpy(parser->tokens[parser->token_count], token);
        parser->token_count++;
        token = strtok(NULL, " ");
    }
}

void DocumentParser_filter_tokens(DocumentParser* parser) {
    int filtered_count = 0;
    for (int i = 0; i < parser->token_count; i++) {
        int is_stop_word = 0;
        for (int j = 0; j < STOP_WORDS_COUNT; j++) {
            if (strcmp(parser->tokens[i], stop_words[j]) == 0) {
                is_stop_word = 1;
                break;
            }
        }
        if (!is_stop_word) {
            strcpy(parser->tokens[filtered_count], parser->tokens[i]);
            filtered_count++;
        }
    }
    parser->token_count = filtered_count;
}

void DataMutator_init(DataMutator* mutator, DocumentParser* parser) {
    mutator->token_count = parser->token_count;
    for (int i = 0; i < parser->token_count; i++) {
        strcpy(mutator->tokens[i], parser->tokens[i]);
    }
    mutator->mutated_token_count = 0;
}

void DataMutator_mutate(DataMutator* mutator) {
    srand(time(NULL));
    for (int i = 0; i < mutator->token_count; i++) {
        if (rand() % 2 == 0) {
            int token_length = strlen(mutator->tokens[i]);
            for (int j = 0; j < token_length / 2; j++) {
                char temp = mutator->tokens[i][j];
                mutator->tokens[i][j] = mutator->tokens[i][token_length - j - 1];
                mutator->tokens[i][token_length - j - 1] = temp;
            }
        }
        strcpy(mutator->mutated_tokens[mutator->mutated_token_count], mutator->tokens[i]);
        mutator->mutated_token_count++;
    }
}

void main() {
    const char* text = "Document parsing and lexical tokenization are important for natural language processing tasks.";
    DocumentParser parser;
    DocumentParser_init(&parser, text);
    DocumentParser_tokenize(&parser);
    DocumentParser_filter_tokens(&parser);

    DataMutator mutator;
    DataMutator_init(&mutator, &parser);
    DataMutator_mutate(&mutator);

    for (int i = 0; i < mutator.mutated_token_count; i++) {
        printf("%s ", mutator.mutated_tokens[i]);
    }
    printf("\n");
}