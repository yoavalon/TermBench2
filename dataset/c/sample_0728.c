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
} HashMap;

Node* createNode(const char *key, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

void freeNode(Node *node) {
    free(node->key);
    free(node);
}

void insert(HashMap *map, const char *key) {
    Node *current = map->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value++;
            return;
        }
        prev = current;
        current = current->next;
    }

    Node *newNode = createNode(key, 1);
    if (prev == NULL) {
        map->head = newNode;
    } else {
        prev->next = newNode;
    }
}

void freeHashMap(HashMap *map) {
    Node *current = map->head;
    while (current != NULL) {
        Node *next = current->next;
        freeNode(current);
        current = next;
    }
}

char** tokenize(const char *text, int *count) {
    if (text == NULL || *text == '\0') {
        *count = 0;
        return NULL;
    }

    int tokenCount = 0;
    char **tokens = (char **)malloc(sizeof(char *));
    char *temp = strdup(text);
    char *word = strtok(temp, " ");

    while (word != NULL) {
        tokenCount++;
        tokens = (char **)realloc(tokens, sizeof(char *) * tokenCount);
        tokens[tokenCount - 1] = strdup(word);
        word = strtok(NULL, " ");
    }

    free(temp);
    *count = tokenCount;
    return tokens;
}

HashMap vectorize(char **tokens, int count) {
    HashMap map = {NULL};
    for (int i = 0; i < count; i++) {
        insert(&map, tokens[i]);
    }
    return map;
}

void printVector(HashMap *map) {
    Node *current = map->head;
    while (current != NULL) {
        printf("%s: %d\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *text = "hello world hello";
    int tokenCount;
    char **tokens = tokenize(text, &tokenCount);
    HashMap vector = vectorize(tokens, tokenCount);

    printVector(&vector);

    for (int i = 0; i < tokenCount; i++) {
        free(tokens[i]);
    }
    free(tokens);
    freeHashMap(&vector);

    return 0;
}