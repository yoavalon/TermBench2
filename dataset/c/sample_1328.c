#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { STRING, LIST, DICT } Type;

typedef struct {
    char *key;
    void *value;
    Type type;
} DictEntry;

typedef struct {
    DictEntry **entries;
    size_t size;
} Dict;

typedef struct {
    void **items;
    size_t size;
} List;

typedef union {
    char *string;
    List list;
} Value;

typedef struct {
    Type type;
    Value value;
} Node;

typedef struct {
    Node **nodes;
    size_t size;
} NodeList;

typedef struct {
    Dict dict;
} Tree;

Dict *create_dict() {
    Dict *dict = (Dict *)malloc(sizeof(Dict));
    dict->entries = NULL;
    dict->size = 0;
    return dict;
}

void add_dict_entry(Dict *dict, const char *key, void *value, Type type) {
    DictEntry *entry = (DictEntry *)malloc(sizeof(DictEntry));
    entry->key = strdup(key);
    entry->value = value;
    entry->type = type;
    dict->entries = (DictEntry **)realloc(dict->entries, (dict->size + 1) * sizeof(DictEntry *));
    dict->entries[dict->size++] = entry;
}

void free_dict(Dict *dict) {
    for (size_t i = 0; i < dict->size; i++) {
        free(dict->entries[i]->key);
        if (dict->entries[i]->type == DICT) {
            free_dict(dict->entries[i]->value);
        } else if (dict->entries[i]->type == LIST) {
            List *list = dict->entries[i]->value;
            for (size_t j = 0; j < list->size; j++) {
                free(list->items[j]);
            }
            free(list->items);
            free(list);
        } else {
            free(dict->entries[i]->value);
        }
        free(dict->entries[i]);
    }
    free(dict->entries);
    free(dict);
}

List *create_list() {
    List *list = (List *)malloc(sizeof(List));
    list->items = NULL;
    list->size = 0;
    return list;
}

void add_list_item(List *list, void *item) {
    list->items = (void **)realloc(list->items, (list->size + 1) * sizeof(void *));
    list->items[list->size++] = item;
}

void free_list(List *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    free(list->items);
    free(list);
}

NodeList *parse_tree(Tree *tree, char ***errors, size_t *error_count) {
    NodeList *node_list = create_list();
    Dict *dict = tree->dict.entries[0]->value;
    for (size_t i = 0; i < dict->size; i++) {
        DictEntry *entry = dict->entries[i];
        if (strcmp(entry->key, "type") != 0 && strcmp(entry->key, "children") != 0) {
            *errors = (char **)realloc(*errors, (*error_count + 1) * sizeof(char *));
            (*errors)[(*error_count)++] = strdup("Unexpected key");
        }
        if (strcmp(entry->key, "type") == 0) {
            if (entry->type != STRING) {
                *errors = (char **)realloc(*errors, (*error_count + 1) * sizeof(char *));
                (*errors)[(*error_count)++] = strdup("Type must be a string");
            }
        }
        if (strcmp(entry->key, "children") == 0) {
            if (entry->type != LIST) {
                *errors = (char **)realloc(*errors, (*error_count + 1) * sizeof(char *));
                (*errors)[(*error_count)++] = strdup("Children must be a list");
            } else {
                List *children = entry->value;
                for (size_t j = 0; j < children->size; j++) {
                    Tree *child_tree = (Tree *)children->items[j];
                    NodeList *child_list = parse_tree(child_tree, errors, error_count);
                    for (size_t k = 0; k < child_list->size; k++) {
                        add_list_item(node_list, child_list->items[k]);
                    }
                    free_list(child_list);
                }
            }
        }
    }
    return node_list;
}

int main() {
    char **errors = NULL;
    size_t error_count = 0;

    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->dict = *create_dict();
    add_dict_entry(&tree->dict, "type", strdup("program"), STRING);

    List *children = create_list();
    for (int i = 0; i < 2; i++) {
        Tree *statement_tree = (Tree *)malloc(sizeof(Tree));
        statement_tree->dict = *create_dict();
        add_dict_entry(&statement_tree->dict, "type", strdup("statement"), STRING);

        List *expression_list = create_list();
        Tree *expression_tree = (Tree *)malloc(sizeof(Tree));
        expression_tree->dict = *create_dict();
        add_dict_entry(&expression_tree->dict, "type", strdup("expression"), STRING);
        add_list_item(expression_list, expression_tree);

        add_dict_entry(&statement_tree->dict, "children", expression_list, LIST);
        add_list_item(children, statement_tree);
    }
    add_dict_entry(&tree->dict, "children", children, LIST);

    NodeList *node_list = parse_tree(tree, &errors, &error_count);
    if (error_count > 0) {
        printf("Errors found in tree:\n");
        for (size_t i = 0; i < error_count; i++) {
            printf("%s\n", errors[i]);
        }
    } else {
        printf("Tree is valid\n");
    }

    for (size_t i = 0; i < error_count; i++) {
        free(errors[i]);
    }
    free(errors);
    free_list(node_list);
    free_dict(&tree->dict);
    free(tree);

    return 0;
}