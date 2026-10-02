c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_SENTENCES 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char *text;
} DocumentParser;

typedef struct {
    char **sentences;
    int sentence_count;
} Tokenizer;

typedef struct {
    char *tokens[MAX_TOKENS];
    int token_count;
} LexicalAnalyzer;

DocumentParser *DocumentParser_init(char *text) {
    DocumentParser *parser = (DocumentParser *)malloc(sizeof(DocumentParser));
    parser->text = strdup(text);
    return parser;
}

char **split_into_sentences(DocumentParser *parser, int *sentence_count) {
    char **sentences = (char **)malloc(MAX_SENTENCES * sizeof(char *));
    char *text = parser->text;
    char *token = strtok(text, ".!?");
    int count = 0;
    while (token != NULL) {
        sentences[count] = strdup(token);
        token = strtok(NULL, ".!?");
        count++;
    }
    *sentence_count = count;
    return sentences;
}

char **tokenize_sentence(char *sentence, int *token_count) {
    char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    char *token = strtok(sentence, " ");
    int count = 0;
    while (token != NULL) {
        tokens[count] = strdup(token);
        token = strtok(NULL, " ");
        count++;
    }
    *token_count = count;
    return tokens;
}

Tokenizer *Tokenizer_init(char **sentences, int sentence_count) {
    Tokenizer *tokenizer = (Tokenizer *)malloc(sizeof(Tokenizer));
    tokenizer->sentences = sentences;
    tokenizer->sentence_count = sentence_count;
    return tokenizer;
}

char **process(Tokenizer *tokenizer, int *token_count) {
    char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    int count = 0;
    for (int i = 0; i < tokenizer->sentence_count; i++) {
        int sentence_token_count;
        char **sentence_tokens = tokenize_sentence(tokenizer->sentences[i], &sentence_token_count);
        for (int j = 0; j < sentence_token_count; j++) {
            tokens[count] = sentence_tokens[j];
            count++;
        }
    }
    *token_count = count;
    return tokens;
}

LexicalAnalyzer *LexicalAnalyzer_init(char **tokens, int token_count) {
    LexicalAnalyzer *analyzer = (LexicalAnalyzer *)malloc(sizeof(LexicalAnalyzer));
    for (int i = 0; i < token_count; i++) {
        analyzer->tokens[i] = tokens[i];
    }
    analyzer->token_count = token_count;
    return analyzer;
}

int count_words(LexicalAnalyzer *analyzer) {
    return analyzer->token_count;
}

void get_unique_words(LexicalAnalyzer *analyzer, char *unique_words[MAX_TOKENS], int *unique_count) {
    for (int i = 0; i < analyzer->token_count; i++) {
        int is_unique = 1;
        for (int j = 0; j < *unique_count; j++) {
            if (strcmp(analyzer->tokens[i], unique_words[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_words[*unique_count] = analyzer->tokens[i];
            (*unique_count)++;
        }
    }
}

void main() {
    char *text = "This is a test. This document is for parsing. Let's see how it works!";
    DocumentParser *parser = DocumentParser_init(text);
    int sentence_count;
    char **sentences = split_into_sentences(parser, &sentence_count);
    Tokenizer *tokenizer = Tokenizer_init(sentences, sentence_count);
    int token_count;
    char **tokens = process(tokenizer, &token_count);
    LexicalAnalyzer *analyzer = LexicalAnalyzer_init(tokens, token_count);
    int word_count = count_words(analyzer);
    char *unique_words[MAX_TOKENS];
    int unique_count = 0;
    get_unique_words(analyzer, unique_words, &unique_count);
    printf("Word Count: %d\n", word_count);
    printf("Unique Words: ");
    for (int i = 0; i < unique_count; i++) {
        printf("%s ", unique_words[i]);
    }
    printf("\n");
}