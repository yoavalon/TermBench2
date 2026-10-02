#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    int index;
    char **tokens;
    int token_count;
    int token_capacity;
} Tokenizer;

void tokenizer_init(Tokenizer *t, const char *text) {
    t->text = strdup(text);
    t->index = 0;
    t->tokens = NULL;
    t->token_count = 0;
    t->token_capacity = 0;
}

void tokenizer_handle_alpha(Tokenizer *t) {
    int start = t->index;
    while (t->index < strlen(t->text) && isalpha(t->text[t->index])) {
        t->index++;
    }
    int length = t->index - start;
    t->tokens = realloc(t->tokens, (t->token_count + 1) * sizeof(char *));
    t->tokens[t->token_count] = strndup(t->text + start, length);
    t->token_count++;
}

void tokenizer_handle_digit(Tokenizer *t) {
    int start = t->index;
    while (t->index < strlen(t->text) && isdigit(t->text[t->index])) {
        t->index++;
    }
    int length = t->index - start;
    char *number_str = strndup(t->text + start, length);
    int number = atoi(number_str);
    free(number_str);

    t->tokens = realloc(t->tokens, (t->token_count + 1) * sizeof(char *));
    t->tokens[t->token_count] = malloc(12); // Assuming max digits in int is 11
    sprintf(t->tokens[t->token_count], "%d", number);
    t->token_count++;
}

char** tokenize(Tokenizer *t) {
    while (t->index < strlen(t->text)) {
        char char_at_index = t->text[t->index];
        if (isalpha(char_at_index)) {
            tokenizer_handle_alpha(t);
        } else if (isdigit(char_at_index)) {
            tokenizer_handle_digit(t);
        } else if (isspace(char_at_index)) {
            t->index++;
        } else {
            t->tokens = realloc(t->tokens, (t->token_count + 1) * sizeof(char *));
            t->tokens[t->token_count] = strdup(&char_at_index);
            t->token_count++;
            t->index++;
        }
    }
    return t->tokens;
}

void tokenizer_free(Tokenizer *t) {
    for (int i = 0; i < t->token_count; i++) {
        free(t->tokens[i]);
    }
    free(t->tokens);
    free(t->text);
}

typedef struct {
    char *text;
    int index;
    char **sentences;
    int sentence_count;
    int sentence_capacity;
} DocumentParser;

void parser_init(DocumentParser *p, const char *text) {
    p->text = strdup(text);
    p->index = 0;
    p->sentences = NULL;
    p->sentence_count = 0;
    p->sentence_capacity = 0;
}

void parser_handle_sentence(DocumentParser *p) {
    int start = p->index;
    while (p->index < strlen(p->text) && p->text[p->index] != '.') {
        p->index++;
    }
    int length = p->index - start + 1;
    p->sentences = realloc(p->sentences, (p->sentence_count + 1) * sizeof(char *));
    p->sentences[p->sentence_count] = strndup(p->text + start, length);
    p->sentence_count++;
    p->index++;
}

void parser_handle_word(DocumentParser *p) {
    while (p->index < strlen(p->text) && !isspace(p->text[p->index]) && p->text[p->index] != '.') {
        p->index++;
    }
}

char** parse(DocumentParser *p) {
    while (p->index < strlen(p->text)) {
        char char_at_index = p->text[p->index];
        if (char_at_index == '.') {
            parser_handle_sentence(p);
        } else if (isspace(char_at_index)) {
            p->index++;
        } else {
            parser_handle_word(p);
        }
    }
    return p->sentences;
}

void parser_free(DocumentParser *p) {
    for (int i = 0; i < p->sentence_count; i++) {
        free(p->sentences[i]);
    }
    free(p->sentences);
    free(p->text);
}

void main() {
    const char *text = "Hello world. This is a test document with several sentences. Each sentence ends with a period.";
    DocumentParser parser;
    parser_init(&parser, text);
    char **sentences = parse(&parser);
    for (int i = 0; i < parser.sentence_count; i++) {
        Tokenizer tokenizer;
        tokenizer_init(&tokenizer, sentences[i]);
        char **tokens = tokenize(&tokenizer);
        for (int j = 0; j < tokenizer.token_count; j++) {
            printf("%s ", tokens[j]);
        }
        printf("\n");
        tokenizer_free(&tokenizer);
    }
    parser_free(&parser);
}