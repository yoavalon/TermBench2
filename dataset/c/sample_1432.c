#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} Tokenizer;

typedef struct {
    char *text;
} DocumentParser;

typedef struct {
    char **data;
    int data_count;
} DataMutator;

void tokenizer_init(Tokenizer *tokenizer, char *text) {
    tokenizer->text = text;
    tokenizer->tokens = NULL;
    tokenizer->token_count = 0;
}

void tokenize(Tokenizer *tokenizer) {
    char *copy = strdup(tokenizer->text);
    char *token = strtok(copy, " ");
    while (token != NULL) {
        tokenizer->tokens = realloc(tokenizer->tokens, (tokenizer->token_count + 1) * sizeof(char *));
        tokenizer->tokens[tokenizer->token_count++] = strdup(token);
        token = strtok(NULL, " ");
    }
    free(copy);
}

void document_parser_init(DocumentParser *parser, char *text) {
    parser->text = strdup(text);
}

void preprocess(DocumentParser *parser) {
    for (int i = 0; parser->text[i]; i++) {
        if (!isalnum(parser->text[i]) && !isspace(parser->text[i])) {
            parser->text[i] = ' ';
        }
    }
    for (int i = 0; parser->text[i]; i++) {
        parser->text[i] = tolower(parser->text[i]);
    }
}

void parse(DocumentParser *parser, Tokenizer *tokenizer) {
    tokenizer_init(tokenizer, parser->text);
    tokenize(tokenizer);
}

void data_mutator_init(DataMutator *mutator, char **data, int data_count) {
    mutator->data = data;
    mutator->data_count = data_count;
}

char **mutate(DataMutator *mutator) {
    for (int i = 0; i < mutator->data_count; i++) {
        for (int j = 0; mutator->data[i][j]; j++) {
            mutator->data[i][j] = toupper(mutator->data[i][j]);
        }
    }
    return mutator->data;
}

void free_tokens(char **tokens, int count) {
    for (int i = 0; i < count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

void free_parser(DocumentParser *parser) {
    free(parser->text);
}

void free_mutator(DataMutator *mutator) {
    // Tokens are already freed in the tokenizer
}

int main() {
    char *document = "This is a sample document for testing. It includes various words!";
    DocumentParser parser;
    Tokenizer tokenizer;
    DataMutator mutator;

    document_parser_init(&parser, document);
    preprocess(&parser);
    parse(&parser, &tokenizer);

    char **tokens = tokenizer.tokens;
    int token_count = tokenizer.token_count;

    data_mutator_init(&mutator, tokens, token_count);
    char **mutated_data = mutate(&mutator);

    for (int i = 0; i < token_count; i++) {
        printf("%s ", mutated_data[i]);
    }
    printf("\n");

    free_tokens(tokens, token_count);
    free_parser(&parser);
    free_mutator(&mutator);

    return 0;
}