#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    char type;
    union {
        double f;
        int i;
        struct {
            int size;
            struct Node **elements;
        } list;
        struct {
            int size;
            char **keys;
            struct Node **values;
        } dict;
    } data;
} Node;

Node* create_float_node(double value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = 'f';
    node->data.f = value;
    return node;
}

Node* create_int_node(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = 'i';
    node->data.i = value;
    return node;
}

Node* create_list_node(int size) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = 'l';
    node->data.list.size = size;
    node->data.list.elements = (Node**)malloc(size * sizeof(Node*));
    return node;
}

Node* create_dict_node(int size) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = 'd';
    node->data.dict.size = size;
    node->data.dict.keys = (char**)malloc(size * sizeof(char*));
    node->data.dict.values = (Node**)malloc(size * sizeof(Node*));
    return node;
}

void free_node(Node *node) {
    if (node == NULL) return;
    if (node->type == 'l') {
        for (int i = 0; i < node->data.list.size; i++) {
            free_node(node->data.list.elements[i]);
        }
        free(node->data.list.elements);
    } else if (node->type == 'd') {
        for (int i = 0; i < node->data.dict.size; i++) {
            free(node->data.dict.keys[i]);
            free_node(node->data.dict.values[i]);
        }
        free(node->data.dict.keys);
        free(node->data.dict.values);
    }
    free(node);
}

Node* process_node(Node *node, int precision) {
    if (node == NULL) return NULL;
    if (node->type == 'f') {
        node->data.f = round(node->data.f * pow(10, precision)) / pow(10, precision);
    } else if (node->type == 'l') {
        for (int i = 0; i < node->data.list.size; i++) {
            node->data.list.elements[i] = process_node(node->data.list.elements[i], precision);
        }
    } else if (node->type == 'd') {
        for (int i = 0; i < node->data.dict.size; i++) {
            node->data.dict.values[i] = process_node(node->data.dict.values[i], precision);
        }
    }
    return node;
}

void lint_tree(Node *tree, int precision) {
    while (1) {
        tree = process_node(tree, precision);
    }
}

int main() {
    Node *tree = create_dict_node(3);
    tree->data.dict.keys[0] = strdup("a");
    tree->data.dict.values[0] = create_float_node(1.23456789);
    tree->data.dict.keys[1] = strdup("b");
    Node *list1 = create_list_node(2);
    list1->data.list.elements[0] = create_float_node(2.3456789);
    list1->data.list.elements[1] = create_float_node(3.45678901);
    tree->data.dict.values[1] = list1;
    tree->data.dict.keys[2] = strdup("c");
    Node *dict1 = create_dict_node(2);
    dict1->data.dict.keys[0] = strdup("d");
    dict1->data.dict.values[0] = create_float_node(4.56789012);
    dict1->data.dict.keys[1] = strdup("e");
    Node *list2 = create_list_node(2);
    list2->data.list.elements[0] = create_float_node(5.67890123);
    list2->data.list.elements[1] = create_float_node(6.78901234);
    dict1->data.dict.values[1] = list2;
    tree->data.dict.values[2] = dict1;

    lint_tree(tree, 4);

    free_node(tree);
    return 0;
}