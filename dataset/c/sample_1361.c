#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *key;
    void *value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Dict;

typedef struct {
    void **items;
    int size;
} List;

void *process_node(void *node) {
    if (node == NULL) {
        return NULL;
    }

    if (node->type == 'D') {
        Dict *dict = (Dict *)node;
        Dict *new_dict = (Dict *)malloc(sizeof(Dict));
        new_dict->head = NULL;
        Node *current = dict->head;
        while (current != NULL) {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->key = strdup(current->key);
            new_node->value = process_node(current->value);
            new_node->next = new_dict->head;
            new_dict->head = new_node;
            current = current->next;
        }
        return new_dict;
    } else if (node->type == 'L') {
        List *list = (List *)node;
        List *new_list = (List *)malloc(sizeof(List));
        new_list->size = list->size;
        new_list->items = (void **)malloc(list->size * sizeof(void *));
        for (int i = 0; i < list->size; i++) {
            new_list->items[i] = process_node(list->items[i]);
        }
        return new_list;
    } else if (node->type == 'S') {
        char *str = (char *)node;
        char *new_str = (char *)malloc(strlen(str) + 1);
        for (int i = 0; str[i]; i++) {
            new_str[i] = toupper(str[i]);
        }
        new_str[strlen(str)] = '\0';
        return new_str;
    } else {
        return node;
    }
}

void lint_tree(void **tree) {
    for (int i = 0; i < 3; i++) {
        *tree = process_node(*tree);
    }
}

void main() {
    Dict *tree = (Dict *)malloc(sizeof(Dict));
    tree->head = NULL;

    Node *node_a = (Node *)malloc(sizeof(Node));
    node_a->key = strdup("a");
    node_a->next = NULL;

    List *list_a = (List *)malloc(sizeof(List));
    list_a->size = 2;
    list_a->items = (void **)malloc(2 * sizeof(void *));
    list_a->items[0] = strdup("b");
    list_a->items[1] = strdup("c");

    node_a->value = list_a;
    node_a->type = 'L';

    Node *node_b = (Node *)malloc(sizeof(Node));
    node_b->key = strdup("b");
    node_b->next = NULL;

    Dict *dict_b = (Dict *)malloc(sizeof(Dict));
    dict_b->head = NULL;

    Node *node_d = (Node *)malloc(sizeof(Node));
    node_d->key = strdup("d");
    node_d->value = strdup("e");
    node_d->next = NULL;

    dict_b->head = node_d;
    dict_b->type = 'D';

    node_b->value = dict_b;
    node_b->type = 'D';

    Node *node_c = (Node *)malloc(sizeof(Node));
    node_c->key = strdup("c");
    node_c->value = strdup("f");
    node_c->next = NULL;
    node_c->type = 'S';

    node_a->next = node_b;
    node_b->next = node_c;

    tree->head = node_a;
    tree->type = 'D';

    void *result;
    lint_tree((void **)&tree);

    printf("%s\n", (char *)tree->head->value);

    // Free allocated memory (omitted for brevity)
}