#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
} DocumentParser;

typedef struct {
    char **tokens;
    int token_count;
} Tokenizer;

void DocumentParser_init(DocumentParser *parser, const char *text) {
    parser->text = strdup(text);
}

void DocumentParser_tokenize(DocumentParser *parser, Tokenizer *tokenizer) {
    char *buffer = (char *)malloc(256 * sizeof(char));
    int buffer_index = 0;
    tokenizer->tokens = (char **)malloc(256 * sizeof(char *));
    tokenizer->token_count = 0;

    for (int i = 0; parser->text[i] != '\0'; i++) {
        char c = parser->text[i];
        if (isalnum(c) || c == '_') {
            buffer[buffer_index++] = c;
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                tokenizer->tokens[tokenizer->token_count++] = strdup(buffer);
                buffer_index = 0;
            }
            if (c != ' ' && c != '\t' && c != '\n') {
                char *single_char_token = (char *)malloc(2 * sizeof(char));
                single_char_token[0] = c;
                single_char_token[1] = '\0';
                tokenizer->tokens[tokenizer->token_count++] = single_char_token;
            }
        }
    }
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        tokenizer->tokens[tokenizer->token_count++] = strdup(buffer);
    }
    free(buffer);
}

void Tokenizer_init(Tokenizer *tokenizer, char **tokens) {
    tokenizer->tokens = tokens;
    tokenizer->token_count = 0;
    while (tokens[tokenizer->token_count] != NULL) {
        tokenizer->token_count++;
    }
}

void Tokenizer_categorize(Tokenizer *tokenizer, char **categorized) {
    for (int i = 0; i < tokenizer->token_count; i++) {
        if (isdigit(tokenizer->tokens[i][0])) {
            categorized[i] = strdup("Number");
        } else if (strchr(tokenizer->tokens[i], '.') != NULL && strchr(tokenizer->tokens[i] + 1, '.') == NULL && isdigit(strchr(tokenizer->tokens[i], '.') + 1)) {
            categorized[i] = strdup("Float");
        } else if (isalnum(tokenizer->tokens[i][0]) || strchr(tokenizer->tokens[i], '_') != NULL) {
            categorized[i] = strdup("Identifier");
        } else {
            categorized[i] = strdup("Operator");
        }
    }
    categorized[tokenizer->token_count] = NULL;
}

void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

void free_categorized(char **categorized) {
    for (int i = 0; categorized[i] != NULL; i++) {
        free(categorized[i]);
    }
    free(categorized);
}

int main() {
    const char *text = "x = 3.14 * 2 + 5.0";
    DocumentParser parser;
    DocumentParser_init(&parser, text);

    Tokenizer tokenizer;
    DocumentParser_tokenize(&parser, &tokenizer);

    char **categorized = (char **)malloc((tokenizer.token_count + 1) * sizeof(char *));
    Tokenizer_categorize(&tokenizer, categorized);

    for (int i = 0; categorized[i] != NULL; i++) {
        printf("%s\n", categorized[i]);
    }

    free_categorized(categorized);
    free_tokens(tokenizer.tokens);
    free(parser.text);

    return 0;
}