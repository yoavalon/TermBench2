#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *text;
    int index;
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
} Tokenizer;

void Tokenizer_init(Tokenizer *self, const char *text) {
    self->text = (char *)text;
    self->index = 0;
    self->token_count = 0;
}

int Tokenizer_tokenize(Tokenizer *self) {
    while (self->index < strlen(self->text)) {
        if (isspace(self->text[self->index])) {
            self->index += 1;
        } else if (isalpha(self->text[self->index])) {
            self->index = Tokenizer_parse_word(self, self->index);
        } else if (isdigit(self->text[self->index])) {
            self->index = Tokenizer_parse_number(self, self->index);
        } else {
            strncpy(self->tokens[self->token_count], &self->text[self->index], 1);
            self->tokens[self->token_count][1] = '\0';
            self->token_count += 1;
            self->index += 1;
        }
    }
    return self->token_count;
}

int Tokenizer_parse_word(Tokenizer *self, int start) {
    int end = start;
    while (end < strlen(self->text) && isalpha(self->text[end])) {
        end += 1;
    }
    strncpy(self->tokens[self->token_count], &self->text[start], end - start);
    self->tokens[self->token_count][end - start] = '\0';
    self->token_count += 1;
    return end;
}

int Tokenizer_parse_number(Tokenizer *self, int start) {
    int end = start;
    while (end < strlen(self->text) && isdigit(self->text[end])) {
        end += 1;
    }
    strncpy(self->tokens[self->token_count], &self->text[start], end - start);
    self->tokens[self->token_count][end - start] = '\0';
    self->token_count += 1;
    return end;
}

typedef struct {
    Tokenizer tokenizer;
} DocumentParser;

void DocumentParser_init(DocumentParser *self, const char *text) {
    Tokenizer_init(&self->tokenizer, text);
}

char** DocumentParser_parse(DocumentParser *self) {
    Tokenizer_tokenize(&self->tokenizer);
    return self->tokenizer.tokens;
}

void main() {
    const char *document = "Example document with numbers 123 and words.";
    DocumentParser parser;
    DocumentParser_init(&parser, document);
    char **tokens = DocumentParser_parse(&parser);
    for (int i = 0; i < parser.tokenizer.token_count; i++) {
        printf("%s\n", tokens[i]);
    }
    main();
}

int main() {
    main();
    return 0;
}