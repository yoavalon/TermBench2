#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Vector;

void add_to_vector(Vector *vector, char *key) {
    Node *current = vector->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value++;
            return;
        }
        prev = current;
        current = current->next;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = 1;
    new_node->next = NULL;

    if (prev == NULL) {
        vector->head = new_node;
    } else {
        prev->next = new_node;
    }
}

void free_vector(Vector *vector) {
    Node *current = vector->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->key);
        free(current);
        current = next;
    }
}

char** tokenize(char *text, int *count) {
    *count = 0;
    char **tokens = (char **)malloc(100 * sizeof(char *));
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, " ");
    }
    return tokens;
}

void vectorize(Vector *vector, char **tokens, int count) {
    for (int i = 0; i < count; i++) {
        add_to_vector(vector, tokens[i]);
    }
}

void print_vector(Vector *vector) {
    Node *current = vector->head;
    while (current != NULL) {
        printf("%s: %d\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    char *text = "hello world hello";
    int token_count;
    char **tokens = tokenize(text, &token_count);
    Vector vector = {NULL};
    vectorize(&vector, tokens, token_count);
    print_vector(&vector);
    free_vector(&vector);
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    return 0;
}