#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum { INT, FLOAT, STRING, BOOL, NONE, LIST, DICT, INVALID } NodeType;

typedef struct Node {
    NodeType type;
    union {
        int intValue;
        float floatValue;
        char *strValue;
        bool boolValue;
        struct List *listValue;
        struct Dict *dictValue;
    } value;
} Node;

typedef struct List {
    Node **nodes;
    int size;
} List;

typedef struct Dict {
    char **keys;
    Node **values;
    int size;
} Dict;

void validate_node(Node *node) {
    if (node->type == LIST) {
        for (int i = 0; i < node->value.listValue->size; i++) {
            validate_node(node->value.listValue->nodes[i]);
        }
    } else if (node->type == DICT) {
        for (int i = 0; i < node->value.dictValue->size; i++) {
            validate_node(node->value.dictValue->values[i]);
            validate_node(node->value.dictValue->keys[i]);
        }
    } else if (node->type != INT && node->type != FLOAT && node->type != STRING && node->type != BOOL && node->type != NONE) {
        fprintf(stderr, "Invalid node type\n");
        exit(EXIT_FAILURE);
    }
}

char* lint_tree(Node *tree) {
    validate_node(tree);
    return "Tree validated";
}

Node* create_int_node(int value) {
    Node *node = malloc(sizeof(Node));
    node->type = INT;
    node->value.intValue = value;
    return node;
}

Node* create_float_node(float value) {
    Node *node = malloc(sizeof(Node));
    node->type = FLOAT;
    node->value.floatValue = value;
    return node;
}

Node* create_string_node(const char *value) {
    Node *node = malloc(sizeof(Node));
    node->type = STRING;
    node->value.strValue = strdup(value);
    return node;
}

Node* create_bool_node(bool value) {
    Node *node = malloc(sizeof(Node));
    node->type = BOOL;
    node->value.boolValue = value;
    return node;
}

Node* create_none_node() {
    Node *node = malloc(sizeof(Node));
    node->type = NONE;
    return node;
}

Node* create_list_node(Node **nodes, int size) {
    Node *node = malloc(sizeof(Node));
    node->type = LIST;
    List *list = malloc(sizeof(List));
    list->nodes = nodes;
    list->size = size;
    node->value.listValue = list;
    return node;
}

Node* create_dict_node(char **keys, Node **values, int size) {
    Node *node = malloc(sizeof(Node));
    node->type = DICT;
    Dict *dict = malloc(sizeof(Dict));
    dict->keys = keys;
    dict->values = values;
    dict->size = size;
    node->value.dictValue = dict;
    return node;
}

void free_node(Node *node) {
    if (node->type == STRING) {
        free(node->value.strValue);
    } else if (node->type == LIST) {
        for (int i = 0; i < node->value.listValue->size; i++) {
            free_node(node->value.listValue->nodes[i]);
        }
        free(node->value.listValue->nodes);
        free(node->value.listValue);
    } else if (node->type == DICT) {
        for (int i = 0; i < node->value.dictValue->size; i++) {
            free(node->value.dictValue->keys[i]);
            free_node(node->value.dictValue->values[i]);
        }
        free(node->value.dictValue->keys);
        free(node->value.dictValue->values);
        free(node->value.dictValue);
    }
    free(node);
}

int main() {
    Node *listNode3 = create_int_node(3);
    Node *dictNodeDeep = create_int_node(4);
    Node *dictNodeNested = create_list_node(&dictNodeDeep, 1);
    Node *dictNodeKey = create_string_node("deep");
    Node *dictNodeValue = create_int_node(4);
    Node *dictNode = create_dict_node(&dictNodeKey, &dictNodeValue, 1);
    Node *listNode2 = create_dict_node(&dictNode, &dictNodeNested, 1);
    Node *listNode1 = create_int_node(1);
    Node *listNodeNone = create_none_node();
    Node *listNode = create_list_node(&listNode1, 3);
    listNode->value.listValue->nodes[1] = listNode2;
    listNode->value.listValue->nodes[2] = listNodeNone;

    try {
        char *result = lint_tree(listNode);
        printf("%s\n", result);
    } catch (ValueError e) {
        printf("%s\n", e);
    }

    free_node(listNode);
    return 0;
}