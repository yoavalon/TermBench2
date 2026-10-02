#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char* text;
    char** tokens;
    int token_count;
    int index;
} SequenceParser;

void SequenceParser_init(SequenceParser* self, const char* text) {
    self->text = text;
    self->tokens = NULL;
    self->token_count = 0;
    self->index = 0;
}

void SequenceParser_tokenize(SequenceParser* self) {
    while (self->index < strlen(self->text)) {
        char c = self->text[self->index];
        if (isdigit(c)) {
            self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
            self->tokens[self->token_count] = SequenceParser_parse_number(self);
            self->token_count++;
        } else if (isalpha(c)) {
            self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
            self->tokens[self->token_count] = SequenceParser_parse_word(self);
            self->token_count++;
        } else if (!isspace(c)) {
            self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
            self->tokens[self->token_count] = malloc(2 * sizeof(char));
            self->tokens[self->token_count][0] = c;
            self->tokens[self->token_count][1] = '\0';
            self->token_count++;
            self->index++;
        }
    }
}

char* SequenceParser_parse_number(SequenceParser* self) {
    int start = self->index;
    while (self->index < strlen(self->text) && isdigit(self->text[self->index])) {
        self->index++;
    }
    int length = self->index - start;
    char* number = malloc((length + 1) * sizeof(char));
    strncpy(number, self->text + start, length);
    number[length] = '\0';
    return number;
}

char* SequenceParser_parse_word(SequenceParser* self) {
    int start = self->index;
    while (self->index < strlen(self->text) && isalpha(self->text[self->index])) {
        self->index++;
    }
    int length = self->index - start;
    char* word = malloc((length + 1) * sizeof(char));
    strncpy(word, self->text + start, length);
    word[length] = '\0';
    return word;
}

typedef struct {
    SequenceParser* parser;
    int* processed;
    int processed_count;
} SequenceProcessor;

void SequenceProcessor_init(SequenceProcessor* self, SequenceParser* parser) {
    self->parser = parser;
    self->processed = NULL;
    self->processed_count = 0;
}

void SequenceProcessor_process(SequenceProcessor* self) {
    for (int i = 0; i < self->parser->token_count; i++) {
        if (isdigit(self->parser->tokens[i][0])) {
            int number = atoi(self->parser->tokens[i]) * 2;
            self->processed = realloc(self->processed, (self->processed_count + 1) * sizeof(int));
            self->processed[self->processed_count] = number;
            self->processed_count++;
        } else if (isalpha(self->parser->tokens[i][0])) {
            self->processed = realloc(self->processed, (self->processed_count + 1) * sizeof(int));
            self->processed[self->processed_count] = toupper(self->parser->tokens[i][0]);
            self->processed_count++;
        } else {
            self->processed = realloc(self->processed, (self->processed_count + 1) * sizeof(int));
            self->processed[self->processed_count] = self->parser->tokens[i][0];
            self->processed_count++;
        }
    }
}

typedef struct {
    SequenceProcessor* processor;
} SequenceDisplay;

void SequenceDisplay_init(SequenceDisplay* self, SequenceProcessor* processor) {
    self->processor = processor;
}

void SequenceDisplay_display(SequenceDisplay* self) {
    while (1) {
        for (int i = 0; i < self->processor->processed_count; i++) {
            printf("%d ", self->processor->processed[i]);
        }
        printf("\n");
    }
}

void main() {
    const char* text = "hello 123 world 456";
    SequenceParser parser;
    SequenceParser_init(&parser, text);
    SequenceParser_tokenize(&parser);
    SequenceProcessor processor;
    SequenceProcessor_init(&processor, &parser);
    SequenceProcessor_process(&processor);
    SequenceDisplay display;
    SequenceDisplay_init(&display, &processor);
    SequenceDisplay_display(&display);
}