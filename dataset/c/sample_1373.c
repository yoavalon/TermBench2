#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum { LIST, DICT, STRING } type;
    union {
        struct {
            int length;
            struct Node** items;
        } list;
        struct {
            int length;
            struct Node** keys;
            struct Node** values;
        } dict;
        char* string;
    } data;
} Node;

void parse_node(Node* node) {
    if (node->type == LIST) {
        for (int i = 0; i < node->data.list.length; i++) {
            parse_node(node->data.list.items[i]);
        }
    } else if (node->type == DICT) {
        for (int i = 0; i < node->data.dict.length; i++) {
            parse_node(node->data.dict.keys[i]);
            parse_node(node->data.dict.values[i]);
        }
    }
}

void check_syntax(Node* tree) {
    parse_node(tree);
}

int main() {
    Node* string_node1 = (Node*)malloc(sizeof(Node));
    string_node1->type = STRING;
    string_node1->data.string = "var";

    Node* string_node2 = (Node*)malloc(sizeof(Node));
    string_node2->type = STRING;
    string_node2->data.string = "func";

    Node* string_node3 = (Node*)malloc(sizeof(Node));
    string_node3->type = STRING;
    string_node3->data.string = "arg";

    Node* string_node4 = (Node*)malloc(sizeof(Node));
    string_node4->type = STRING;
    string_node4->data.string = "value";

    Node* dict_node = (Node*)malloc(sizeof(Node));
    dict_node->type = DICT;
    dict_node->data.dict.length = 1;
    dict_node->data.dict.keys = (Node**)malloc(sizeof(Node*));
    dict_node->data.dict.values = (Node**)malloc(sizeof(Node*));
    dict_node->data.dict.keys[0] = string_node3;
    dict_node->data.dict.values[0] = string_node4;

    Node* list_node = (Node*)malloc(sizeof(Node));
    list_node->type = LIST;
    list_node->data.list.length = 3;
    list_node->data.list.items = (Node**)malloc(sizeof(Node*) * 3);
    list_node->data.list.items[0] = string_node1;
    list_node->data.list.items[1] = string_node2;
    list_node->data.list.items[2] = dict_node;

    Node* root_node = (Node*)malloc(sizeof(Node));
    root_node->type = DICT;
    root_node->data.dict.length = 1;
    root_node->data.dict.keys = (Node**)malloc(sizeof(Node*));
    root_node->data.dict.values = (Node**)malloc(sizeof(Node*));
    root_node->data.dict.keys[0] = string_node1;
    root_node->data.dict.values[0] = list_node;

    check_syntax(root_node);

    // Free allocated memory
    free(string_node1);
    free(string_node2);
    free(string_node3);
    free(string_node4);
    free(dict_node->data.dict.keys);
    free(dict_node->data.dict.values);
    free(dict_node);
    free(list_node->data.list.items);
    free(list_node);
    free(root_node->data.dict.keys);
    free(root_node->data.dict.values);
    free(root_node);

    return 0;
}