#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char *text;
    char **tokens;
    int token_capacity;
    int token_count;
    int pos;
} Tokenizer;

void tokenizer_init(Tokenizer *tokenizer, const char *text) {
    tokenizer->text = text;
    tokenizer->tokens = NULL;
    tokenizer->token_capacity = 0;
    tokenizer->token_count = 0;
    tokenizer->pos = 0;
}

void tokenizer_resize(Tokenizer *tokenizer) {
    if (tokenizer->tokens == NULL) {
        tokenizer->tokens = (char **)malloc(4 * sizeof(char *));
        tokenizer->token_capacity = 4;
    } else {
        tokenizer->tokens = (char **)realloc(tokenizer->tokens, (tokenizer->token_capacity * 2) * sizeof(char *));
        tokenizer->token_capacity *= 2;
    }
}

void tokenizer_add_token(Tokenizer *tokenizer, const char *token, int length) {
    if (tokenizer->token_count >= tokenizer->token_capacity) {
        tokenizer_resize(tokenizer);
    }
    tokenizer->tokens[tokenizer->token_count] = (char *)malloc((length + 1) * sizeof(char));
    strncpy(tokenizer->tokens[tokenizer->token_count], token, length);
    tokenizer->tokens[tokenizer->token_count][length] = '\0';
    tokenizer->token_count++;
}

void tokenizer_read_next_token(Tokenizer *tokenizer) {
    while (tokenizer->pos < strlen(tokenizer->text) && isspace(tokenizer->text[tokenizer->pos])) {
        tokenizer->pos++;
    }
    if (tokenizer->pos == strlen(tokenizer->text)) {
        return;
    }
    int start = tokenizer->pos;
    if (isalpha(tokenizer->text[tokenizer->pos])) {
        while (tokenizer->pos < strlen(tokenizer->text) && isalnum(tokenizer->text[tokenizer->pos])) {
            tokenizer->pos++;
        }
        tokenizer_add_token(tokenizer, tokenizer->text + start, tokenizer->pos - start);
    } else if (isdigit(tokenizer->text[tokenizer->pos])) {
        while (tokenizer->pos < strlen(tokenizer->text) && isdigit(tokenizer->text[tokenizer->pos])) {
            tokenizer->pos++;
        }
        tokenizer_add_token(tokenizer, tokenizer->text + start, tokenizer->pos - start);
    } else {
        tokenizer->pos++;
        tokenizer_add_token(tokenizer, tokenizer->text + start, tokenizer->pos - start);
    }
}

char **tokenizer_tokenize(Tokenizer *tokenizer) {
    tokenizer->tokens = NULL;
    tokenizer->token_capacity = 0;
    tokenizer->token_count = 0;
    tokenizer->pos = 0;
    while (tokenizer->pos < strlen(tokenizer->text)) {
        tokenizer_read_next_token(tokenizer);
    }
    return tokenizer->tokens;
}

typedef struct {
    const char *text;
    Tokenizer parser;
} DocumentParser;

void document_parser_init(DocumentParser *parser, const char *text) {
    parser->text = text;
    tokenizer_init(&parser->parser, text);
}

char **document_parser_parse(DocumentParser *parser) {
    return tokenizer_tokenize(&parser->parser);
}

void main() {
    const char *text = "This is a sample text for document parsing.";
    DocumentParser parser;
    document_parser_init(&parser, text);
    char **tokens = document_parser_parse(&parser);
    for (int i = 0; i < parser.parser.token_count; i++) {
        printf("%s ", parser.parser.tokens[i]);
        free(parser.parser.tokens[i]);
    }
    free(parser.parser.tokens);
    main();
}

main();