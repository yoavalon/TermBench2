#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;
    int size;
} HashMap;

unsigned int hash(const char *key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 33) ^ *key++;
    }
    return hash % size;
}

void put(HashMap *map, const char *key, int value) {
    unsigned int index = hash(key, map->size);
    Entry *entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
}

int get(HashMap *map, const char *key) {
    unsigned int index = hash(key, map->size);
    Entry *entry = map->buckets[index];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return 0;
}

void free_map(HashMap *map) {
    for (int i = 0; i < map->size; i++) {
        Entry *entry = map->buckets[i];
        while (entry) {
            Entry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(map->buckets);
    free(map);
}

char **tokenize(const char *text, int *length) {
    if (!text || *text == '\0') {
        *length = 0;
        return NULL;
    }
    char **tokens = (char **)malloc(100 * sizeof(char *));
    int count = 0;
    const char *start = text;
    const char *end = text;
    while (*end) {
        if (*end == ' ') {
            int len = end - start;
            tokens[count] = (char *)malloc((len + 1) * sizeof(char));
            strncpy(tokens[count], start, len);
            tokens[count][len] = '\0';
            count++;
            start = end + 1;
        }
        end++;
    }
    int len = end - start;
    tokens[count] = (char *)malloc((len + 1) * sizeof(char));
    strncpy(tokens[count], start, len);
    tokens[count][len] = '\0';
    count++;
    *length = count;
    return tokens;
}

HashMap *vectorize(char **tokens, int length) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->size = 100;
    map->buckets = (Entry **)calloc(map->size, sizeof(Entry *));
    for (int i = 0; i < length; i++) {
        int count = get(map, tokens[i]);
        put(map, tokens[i], count + 1);
    }
    return map;
}

void print_map(HashMap *map) {
    for (int i = 0; i < map->size; i++) {
        Entry *entry = map->buckets[i];
        while (entry) {
            printf("%s: %d\n", entry->key, entry->value);
            entry = entry->next;
        }
    }
}

void free_tokens(char **tokens, int length) {
    for (int i = 0; i < length; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main() {
    const char *text = "hello world hello";
    int length;
    char **tokens = tokenize(text, &length);
    HashMap *vector = vectorize(tokens, length);
    print_map(vector);
    free_map(vector);
    free_tokens(tokens, length);
    return 0;
}