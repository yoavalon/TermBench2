#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *text;
    int index;
} Tokenizer;

typedef struct {
    char **tokens;
    int token_count;
} Vectorizer;

void tokenizer_init(Tokenizer *tokenizer, const char *text) {
    tokenizer->text = strdup(text);
    tokenizer->index = 0;
}

void tokenizer_free(Tokenizer *tokenizer) {
    free(tokenizer->text);
}

char* read_alpha(Tokenizer *tokenizer) {
    int start = tokenizer->index;
    while (tokenizer->index < strlen(tokenizer->text) && isalpha(tokenizer->text[tokenizer->index])) {
        tokenizer->index++;
    }
    int len = tokenizer->index - start;
    char *token = (char *)malloc(len + 1);
    strncpy(token, tokenizer->text + start, len);
    token[len] = '\0';
    return token;
}

void skip_space(Tokenizer *tokenizer) {
    while (tokenizer->index < strlen(tokenizer->text) && isspace(tokenizer->text[tokenizer->index])) {
        tokenizer->index++;
    }
}

char** tokenize(Tokenizer *tokenizer, int *token_count) {
    char **tokens = (char **)malloc(100 * sizeof(char *));
    *token_count = 0;
    while (tokenizer->index < strlen(tokenizer->text)) {
        if (isalpha(tokenizer->text[tokenizer->index])) {
            tokens[(*token_count)++] = read_alpha(tokenizer);
        } else if (isspace(tokenizer->text[tokenizer->index])) {
            skip_space(tokenizer);
        } else {
            tokenizer->index++;
        }
    }
    return tokens;
}

void vectorizer_init(Vectorizer *vectorizer, char **tokens, int token_count) {
    vectorizer->tokens = tokens;
    vectorizer->token_count = token_count;
}

void vectorizer_free(Vectorizer *vectorizer) {
    for (int i = 0; i < vectorizer->token_count; i++) {
        free(vectorizer->tokens[i]);
    }
    free(vectorizer->tokens);
}

void vectorize(Vectorizer *vectorizer) {
    for (int i = 0; i < vectorizer->token_count; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(vectorizer->tokens[i], vectorizer->tokens[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int j = i + 1; j < vectorizer->token_count; j++) {
                if (strcmp(vectorizer->tokens[i], vectorizer->tokens[j]) == 0) {
                    vectorizer->tokens[j] = NULL;
                }
            }
        }
    }
}

void print_vector(Vectorizer *vectorizer) {
    for (int i = 0; i < vectorizer->token_count; i++) {
        if (vectorizer->tokens[i] != NULL) {
            int count = 0;
            for (int j = 0; j < vectorizer->token_count; j++) {
                if (vectorizer->tokens[j] != NULL && strcmp(vectorizer->tokens[i], vectorizer->tokens[j]) == 0) {
                    count++;
                }
            }
            printf("%s: %d\n", vectorizer->tokens[i], count);
        }
    }
}

int main() {
    const char *text = "This is a sample text for vectorization.";
    Tokenizer tokenizer;
    tokenizer_init(&tokenizer, text);
    int token_count;
    char **tokens = tokenize(&tokenizer, &token_count);
    tokenizer_free(&tokenizer);

    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, tokens, token_count);
    vectorize(&vectorizer);
    print_vector(&vectorizer);
    vectorizer_free(&vectorizer);

    return 0;
}