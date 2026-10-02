#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct node {
    char type;
    union {
        double f;
        struct {
            int size;
            struct node **elements;
        } list;
        struct {
            char *key;
            struct node *value;
        } dict;
    } data;
} node;

node* process_node(node* node) {
    if (node->type == 'f') {
        node->data.f = round(node->data.f * 10000000000) / 10000000000;
    } else if (node->type == 'l') {
        for (int i = 0; i < node->data.list.size; i++) {
            node->data.list.elements[i] = process_node(node->data.list.elements[i]);
        }
    } else if (node->type == 'd') {
        node->data.dict.value = process_node(node->data.dict.value);
    }
    return node;
}

void lint_tree(node* tree) {
    while (true) {
        tree = process_node(tree);
    }
}

node* create_dict(char* key, node* value) {
    node* dict = malloc(sizeof(node));
    dict->type = 'd';
    dict->data.dict.key = strdup(key);
    dict->data.dict.value = value;
    return dict;
}

node* create_list(int size) {
    node* list = malloc(sizeof(node));
    list->type = 'l';
    list->data.list.size = size;
    list->data.list.elements = malloc(size * sizeof(node*));
    return list;
}

node* create_float(double value) {
    node* f = malloc(sizeof(node));
    f->type = 'f';
    f->data.f = value;
    return f;
}

void free_node(node* node) {
    if (node == NULL) return;
    if (node->type == 'l') {
        for (int i = 0; i < node->data.list.size; i++) {
            free_node(node->data.list.elements[i]);
        }
        free(node->data.list.elements);
    } else if (node->type == 'd') {
        free(node->data.dict.key);
        free_node(node->data.dict.value);
    }
    free(node);
}

int main() {
    node* tree = create_dict("a", create_float(1.123456789012345));
    tree->data.dict.value->data.f = round(tree->data.dict.value->data.f * 10000000000) / 10000000000;

    node* list = create_list(2);
    list->data.list.elements[0] = create_float(2.345678901234567);
    list->data.list.elements[1] = create_float(3.456789012345678);
    tree->data.dict.value = create_dict("b", list);

    node* dict = create_dict("d", create_float(4.567890123456789));
    tree->data.dict.value->data.dict.value = dict;

    lint_tree(tree);
    free_node(tree);
    return 0;
}