#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* type;
    void* value;
} Node;

typedef struct List {
    Node** elements;
    int size;
} List;

typedef struct Dict {
    char** keys;
    Node** values;
    int size;
} Dict;

void* mutate_node(Node* node) {
    if (strcmp(node->type, "list") == 0) {
        List* list = (List*)node->value;
        for (int i = 0; i < list->size; i++) {
            list->elements[i] = (Node*)mutate_node(list->elements[i]);
        }
    } else if (strcmp(node->type, "dict") == 0) {
        Dict* dict = (Dict*)node->value;
        for (int i = 0; i < dict->size; i++) {
            dict->values[i] = (Node*)mutate_node(dict->values[i]);
        }
    } else if (strcmp(node->type, "str") == 0) {
        char* str = (char*)node->value;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == 'a') str[i] = 'b';
            else if (str[i] == 'b') str[i] = 'a';
        }
    }
    return node;
}

void process_tree(Node* tree) {
    while (1) {
        tree = (Node*)mutate_node(tree);
    }
}

int main() {
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->type = "dict";
    tree->value = (void*)malloc(sizeof(Dict));
    Dict* dict = (Dict*)tree->value;
    dict->keys = (char**)malloc(2 * sizeof(char*));
    dict->values = (Node**)malloc(2 * sizeof(Node*));
    dict->size = 2;

    dict->keys[0] = "node1";
    dict->values[0] = (Node*)malloc(sizeof(Node));
    dict->values[0]->type = "list";
    dict->values[0]->value = (void*)malloc(sizeof(List));
    List* list1 = (List*)dict->values[0]->value;
    list1->elements = (Node**)malloc(2 * sizeof(Node*));
    list1->size = 2;

    list1->elements[0] = (Node*)malloc(sizeof(Node));
    list1->elements[0]->type = "str";
    list1->elements[0]->value = (void*)strdup("leaf1");

    list1->elements[1] = (Node*)malloc(sizeof(Node));
    list1->elements[1]->type = "str";
    list1->elements[1]->value = (void*)strdup("leaf2");

    dict->keys[1] = "node2";
    dict->values[1] = (Node*)malloc(sizeof(Node));
    dict->values[1]->type = "dict";
    dict->values[1]->value = (void*)malloc(sizeof(Dict));
    Dict* dict2 = (Dict*)dict->values[1]->value;
    dict2->keys = (char**)malloc(2 * sizeof(char*));
    dict2->values = (Node**)malloc(2 * sizeof(Node*));
    dict2->size = 2;

    dict2->keys[0] = "subnode1";
    dict2->values[0] = (Node*)malloc(sizeof(Node));
    dict2->values[0]->type = "str";
    dict2->values[0]->value = (void*)strdup("value1");

    dict2->keys[1] = "subnode2";
    dict2->values[1] = (Node*)malloc(sizeof(Node));
    dict2->values[1]->type = "list";
    dict2->values[1]->value = (void*)malloc(sizeof(List));
    List* list2 = (List*)dict2->values[1]->value;
    list2->elements = (Node**)malloc(2 * sizeof(Node*));
    list2->size = 2;

    list2->elements[0] = (Node*)malloc(sizeof(Node));
    list2->elements[0]->type = "str";
    list2->elements[0]->value = (void*)strdup("value2");

    list2->elements[1] = (Node*)malloc(sizeof(Node));
    list2->elements[1]->type = "str";
    list2->elements[1]->value = (void*)strdup("value3");

    process_tree(tree);

    return 0;
}