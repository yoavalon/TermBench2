c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    void* value;
} dict_entry;

typedef struct {
    dict_entry* entries;
    int size;
    int capacity;
} dict;

typedef struct {
    void* elements;
    int size;
    int capacity;
} list;

typedef struct {
    char* type;
    char* name;
    void* body;
} function;

typedef struct {
    char* type;
    char* content;
} statement;

typedef struct {
    char* type;
    void* body;
} module;

void* create_dict() {
    dict* d = malloc(sizeof(dict));
    d->size = 0;
    d->capacity = 1;
    d->entries = malloc(sizeof(dict_entry) * d->capacity);
    return d;
}

void dict_set(dict* d, const char* key, void* value) {
    for (int i = 0; i < d->size; i++) {
        if (strcmp(d->entries[i].key, key) == 0) {
            d->entries[i].value = value;
            return;
        }
    }
    if (d->size >= d->capacity) {
        d->capacity *= 2;
        d->entries = realloc(d->entries, sizeof(dict_entry) * d->capacity);
    }
    d->entries[d->size].key = strdup(key);
    d->entries[d->size].value = value;
    d->size++;
}

void* dict_get(dict* d, const char* key) {
    for (int i = 0; i < d->size; i++) {
        if (strcmp(d->entries[i].key, key) == 0) {
            return d->entries[i].value;
        }
    }
    return NULL;
}

void* create_list() {
    list* l = malloc(sizeof(list));
    l->size = 0;
    l->capacity = 1;
    l->elements = malloc(sizeof(void*) * l->capacity);
    return l;
}

void list_append(list* l, void* item) {
    if (l->size >= l->capacity) {
        l->capacity *= 2;
        l->elements = realloc(l->elements, sizeof(void*) * l->capacity);
    }
    ((void**)l->elements)[l->size] = item;
    l->size++;
}

void check_ast(void* node) {
    if (node == NULL) return;
    if (list* l = (list*)node; l->elements != NULL) {
        for (int i = 0; i < l->size; i++) {
            check_ast(((void**)l->elements)[i]);
        }
    } else if (dict* d = (dict*)node; d->entries != NULL) {
        for (int i = 0; i < d->size; i++) {
            if (strcmp(d->entries[i].key, "type") == 0 && strcmp((char*)dict_get(d, "type"), "function") == 0) {
                fprintf(stderr, "Function definition detected\n");
                exit(1);
            }
            check_ast(d->entries[i].value);
        }
    }
}

void lint_code(void* code) {
    check_ast(code);
}

void main() {
    dict* code_structure = (dict*)create_dict();
    dict_set(code_structure, "type", strdup("module"));
    list* body = (list*)create_list();
    dict* statement1 = (dict*)create_dict();
    dict_set(statement1, "type", strdup("statement"));
    dict_set(statement1, "content", strdup("x = 10"));
    list_append(body, statement1);
    dict* function1 = (dict*)create_dict();
    dict_set(function1, "type", strdup("function"));
    dict_set(function1, "name", strdup("my_func"));
    dict_set(function1, "body", (void*)create_list());
    list_append(body, function1);
    dict_set(code_structure, "body", body);
    lint_code(code_structure);
}