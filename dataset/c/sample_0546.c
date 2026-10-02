#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct {
    char* text;
    char** tokens;
    int token_count;
} DocumentParser;

typedef struct {
    DocumentParser* parser;
} Tokenizer;

typedef struct {
    Tokenizer* tokenizer;
} Processor;

void DocumentParser_init(DocumentParser* self, const char* text) {
    self->text = strdup(text);
    self->tokens = NULL;
    self->token_count = 0;
}

void DocumentParser_tokenize(DocumentParser* self) {
    regex_t regex;
    regmatch_t pmatch[2];
    char* text = self->text;
    int len = strlen(text);
    int pos = 0;

    if (regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    while (pos < len) {
        if (regexec(&regex, text + pos, 2, pmatch, 0) == 0) {
            int start = pmatch[0].rm_so + pos;
            int end = pmatch[0].rm_eo + pos;
            int token_len = end - start;
            self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
            self->tokens[self->token_count] = malloc(token_len + 1);
            strncpy(self->tokens[self->token_count], text + start, token_len);
            self->tokens[self->token_count][token_len] = '\0';
            self->token_count++;
            pos = end;
        } else {
            break;
        }
    }

    regfree(&regex);
}

void DocumentParser_process_tokens(DocumentParser* self) {
    for (int i = 0; i < self->token_count; i++) {
        for (int j = 0; self->tokens[i][j]; j++) {
            self->tokens[i][j] = tolower(self->tokens[i][j]);
        }
    }
}

void Tokenizer_init(Tokenizer* self, DocumentParser* parser) {
    self->parser = parser;
}

void Tokenizer_run(Tokenizer* self) {
    DocumentParser_tokenize(self->parser);
    DocumentParser_process_tokens(self->parser);
}

void Processor_init(Processor* self, Tokenizer* tokenizer) {
    self->tokenizer = tokenizer;
}

void Processor_execute(Processor* self) {
    while (1) {
        Tokenizer_run(self->tokenizer);
    }
}

int main() {
    const char* text = "Document parsing and lexical tokenization is crucial for natural language processing.";
    DocumentParser parser;
    Tokenizer tokenizer;
    Processor processor;

    DocumentParser_init(&parser, text);
    Tokenizer_init(&tokenizer, &parser);
    Processor_init(&processor, &tokenizer);
    Processor_execute(&processor);

    return 0;
}