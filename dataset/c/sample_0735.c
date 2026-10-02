#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    int size;
} HashMap;

unsigned int hash(const char *key, int size) {
    unsigned int hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % size;
}

void put(HashMap *map, const char *key, int value) {
    unsigned int index = hash(key, map->size);
    HashNode *node = map->buckets[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    node = (HashNode *)malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = map->buckets[index];
    map->buckets[index] = node;
}

int get(HashMap *map, const char *key) {
    unsigned int index = hash(key, map->size);
    HashNode *node = map->buckets[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return 0;
}

void freeHashMap(HashMap *map) {
    for (int i = 0; i < map->size; i++) {
        HashNode *node = map->buckets[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

char** tokenize(const char *text, int *length) {
    if (text == NULL || text[0] == '\0') {
        *length = 0;
        return NULL;
    }
    int count = 1;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ')
            count++;
    }
    char **tokens = (char **)malloc(count * sizeof(char *));
    int i = 0, j = 0, k = 0;
    while (text[i] != '\0') {
        if (text[i] == ' ') {
            tokens[j] = (char *)malloc((k + 1) * sizeof(char));
            strncpy(tokens[j], text + i - k, k);
            tokens[j][k] = '\0';
            j++;
            k = 0;
        } else {
            k++;
        }
        i++;
    }
    tokens[j] = (char *)malloc((k + 1) * sizeof(char));
    strncpy(tokens[j], text + i - k, k);
    tokens[j][k] = '\0';
    j++;
    *length = j;
    return tokens;
}

void vectorize(char **tokens, int length, HashMap *vec) {
    for (int i = 0; i < length; i++) {
        int count = get(vec, tokens[i]);
        put(vec, tokens[i], count + 1);
    }
}

void printHashMap(HashMap *map) {
    for (int i = 0; i < map->size; i++) {
        HashNode *node = map->buckets[i];
        while (node != NULL) {
            printf("%s: %d\n", node->key, node->value);
            node = node->next;
        }
    }
}

void freeTokens(char **tokens, int length) {
    for (int i = 0; i < length; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main() {
    const char *text = "hello world hello";
    int length;
    char **tokens = tokenize(text, &length);
    HashMap *vec = (HashMap *)malloc(sizeof(HashMap));
    vec->size = 100;
    vec->buckets = (HashNode **)calloc(vec->size, sizeof(HashNode *));
    vectorize(tokens, length, vec);
    printHashMap(vec);
    freeTokens(tokens, length);
    freeHashMap(vec);
    return 0;
}