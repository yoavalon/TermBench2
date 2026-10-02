#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    const char* text;
    int index;
    char** tokens;
    int token_count;
} DocumentTokenizer;

void DocumentTokenizer_init(DocumentTokenizer* self, const char* text) {
    self->text = text;
    self->index = 0;
    self->tokens = NULL;
    self->token_count = 0;
}

int DocumentTokenizer_parse_word(DocumentTokenizer* self) {
    int start = self->index;
    while (self->index < strlen(self->text) && isalpha(self->text[self->index])) {
        self->index += 1;
    }
    int word_length = self->index - start;
    self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
    self->tokens[self->token_count] = malloc((word_length + 1) * sizeof(char));
    strncpy(self->tokens[self->token_count], self->text + start, word_length);
    self->tokens[self->token_count][word_length] = '\0';
    self->token_count += 1;
    return self->index;
}

char** DocumentTokenizer_tokenize(DocumentTokenizer* self) {
    while (self->index < strlen(self->text)) {
        char char = self->text[self->index];
        if (isalpha(char)) {
            self->index = DocumentTokenizer_parse_word(self);
        } else if (isspace(char)) {
            self->index += 1;
        } else {
            self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
            self->tokens[self->token_count] = malloc(2 * sizeof(char));
            self->tokens[self->token_count][0] = char;
            self->tokens[self->token_count][1] = '\0';
            self->token_count += 1;
            self->index += 1;
        }
    }
    return self->tokens;
}

char** process_document(const char* document) {
    DocumentTokenizer tokenizer;
    DocumentTokenizer_init(&tokenizer, document);
    return DocumentTokenizer_tokenize(&tokenizer);
}

void main() {
    const char* document = "Hello world! This is a test document.";
    char** result = process_document(document);
    for (int i = 0; i < 8; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
}