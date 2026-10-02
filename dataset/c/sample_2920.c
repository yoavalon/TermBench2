#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char **tokens;
    int size;
    int front;
    int rear;
} Deque;

Deque *create_deque() {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->tokens = (char **)malloc(100 * sizeof(char *));
    deque->size = 100;
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

void enqueue(Deque *deque, char *token) {
    if (deque->rear == deque->size - 1) {
        printf("Deque is full\n");
        return;
    }
    deque->rear++;
    deque->tokens[deque->rear] = (char *)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    strcpy(deque->tokens[deque->rear], token);
    if (deque->front == -1) {
        deque->front = 0;
    }
}

char *dequeue(Deque *deque) {
    if (deque->front == -1) {
        return NULL;
    }
    char *token = deque->tokens[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front++;
    }
    return token;
}

int is_empty(Deque *deque) {
    return deque->front == -1;
}

typedef struct {
    char text[MAX_TEXT_LENGTH];
    Deque *tokens;
} SequenceParser;

void parse(SequenceParser *parser) {
    char *token = strtok(parser->text, " .,!\n");
    while (token != NULL) {
        enqueue(parser->tokens, token);
        token = strtok(NULL, " .,!\n");
    }
}

char *get_next_token(SequenceParser *parser) {
    if (!is_empty(parser->tokens)) {
        return dequeue(parser->tokens);
    }
    return NULL;
}

typedef struct {
    SequenceParser *parser;
} TokenAnalyzer;

void analyze(TokenAnalyzer *analyzer) {
    while (1) {
        char *token = get_next_token(analyzer->parser);
        if (token) {
            printf("%s\n", token);
            free(token);
        } else {
            break;
        }
    }
}

typedef struct {
    TokenAnalyzer *analyzer;
} SequenceGenerator;

void generate(SequenceGenerator *generator) {
    while (1) {
        analyze(generator->analyzer);
    }
}

void main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The dog barks back.";
    SequenceParser *parser = (SequenceParser *)malloc(sizeof(SequenceParser));
    strcpy(parser->text, text);
    parser->tokens = create_deque();
    parse(parser);

    TokenAnalyzer *analyzer = (TokenAnalyzer *)malloc(sizeof(TokenAnalyzer));
    analyzer->parser = parser;

    SequenceGenerator *generator = (SequenceGenerator *)malloc(sizeof(SequenceGenerator));
    generator->analyzer = analyzer;

    generate(generator);
}