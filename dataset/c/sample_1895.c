#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

typedef struct {
    const char *key;
    void *value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

typedef struct {
    Node *head;
} Dict;

bool check_float_precision(float node) {
    char str[20];
    sprintf(str, "%.17g", node);
    return strcmp(str, repr(node)) == 0;
}

bool check_list_precision(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        if (!check_float_precision(*(float *)current->value)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

bool check_dict_precision(Dict *dict) {
    Node *current = dict->head;
    while (current != NULL) {
        if (!check_float_precision(*(float *)current->value)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

bool check_node_precision(void *node) {
    if (node == NULL) {
        return true;
    }
    if (check_float_precision(*(float *)node)) {
        return true;
    }
    if (check_list_precision((List *)node)) {
        return true;
    }
    if (check_dict_precision((Dict *)node)) {
        return true;
    }
    return false;
}

void main() {
    Dict data;
    data.head = NULL;

    Node *node_f = (Node *)malloc(sizeof(Node));
    node_f->key = "f";
    node_f->value = malloc(sizeof(float));
    *(float *)node_f->value = 6.6;
    node_f->next = NULL;

    Node *node_e = (Node *)malloc(sizeof(Node));
    node_e->key = "e";
    node_e->value = malloc(sizeof(List));
    List *list_e = (List *)node_e->value;
    list_e->head = NULL;

    Node *node_e1 = (Node *)malloc(sizeof(Node));
    node_e1->value = malloc(sizeof(float));
    *(float *)node_e1->value = 5.5;
    node_e1->next = node_f;

    list_e->head = node_e1;

    node_e->next = NULL;

    Node *node_d = (Node *)malloc(sizeof(Node));
    node_d->key = "d";
    node_d->value = malloc(sizeof(float));
    *(float *)node_d->value = 4.4;
    node_d->next = NULL;

    Node *node_c = (Node *)malloc(sizeof(Node));
    node_c->key = "c";
    node_c->value = malloc(sizeof(Dict));
    Dict *dict_c = (Dict *)node_c->value;
    dict_c->head = NULL;

    dict_c->head = node_d;
    dict_c->head->next = node_e;

    node_c->next = NULL;

    Node *node_b1 = (Node *)malloc(sizeof(Node));
    node_b1->value = malloc(sizeof(float));
    *(float *)node_b1->value = 3.3;
    node_b1->next = NULL;

    Node *node_b = (Node *)malloc(sizeof(Node));
    node_b->key = "b";
    node_b->value = malloc(sizeof(List));
    List *list_b = (List *)node_b->value;
    list_b->head = NULL;

    list_b->head = node_b1;

    node_b->next = NULL;

    Node *node_a = (Node *)malloc(sizeof(Node));
    node_a->key = "a";
    node_a->value = malloc(sizeof(float));
    *(float *)node_a->value = 1.1;
    node_a->next = NULL;

    data.head = node_a;
    data.head->next = node_b;
    data.head->next->next = node_c;

    bool result = check_node_precision(data.head);

    printf("%d\n", result);

    // Free allocated memory
    // ...
}