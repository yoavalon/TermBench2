#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FLOAT,
    LIST,
    OTHER
} NodeType;

typedef struct Node {
    NodeType type;
    union {
        float f;
        struct List {
            int size;
            struct Node **elements;
        } list;
    } data;
} Node;

Node* create_float_node(float value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = FLOAT;
    node->data.f = value;
    return node;
}

Node* create_list_node(int size) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = LIST;
    node->data.list.size = size;
    node->data.list.elements = (Node**)malloc(size * sizeof(Node*));
    return node;
}

void free_node(Node *node) {
    if (node == NULL) return;
    if (node->type == LIST) {
        for (int i = 0; i < node->data.list.size; i++) {
            free_node(node->data.list.elements[i]);
        }
        free(node->data.list.elements);
    }
    free(node);
}

char* lint_ast(Node *node) {
    if (node->type == FLOAT) {
        char *str = (char*)malloc(20);
        sprintf(str, "%f", node->data.f);
        return str;
    } else if (node->type == LIST) {
        char *result = (char*)malloc(1024);
        result[0] = '\0';
        strcat(result, "[");
        for (int i = 0; i < node->data.list.size; i++) {
            char *str = lint_ast(node->data.list.elements[i]);
            strcat(result, str);
            free(str);
            if (i < node->data.list.size - 1) {
                strcat(result, ", ");
            }
        }
        strcat(result, "]");
        return result;
    } else {
        return strdup("OTHER");
    }
}

void main() {
    Node *test_data = create_list_node(5);
    test_data->data.list.elements[0] = create_float_node(1.0);
    Node *sublist1 = create_list_node(2);
    sublist1->data.list.elements[0] = create_float_node(2.0);
    sublist1->data.list.elements[1] = create_float_node(3.0);
    test_data->data.list.elements[1] = sublist1;
    test_data->data.list.elements[2] = create_float_node(4.0);
    Node *sublist2 = create_list_node(2);
    sublist2->data.list.elements[0] = create_float_node(5.0);
    Node *subsublist = create_list_node(2);
    subsublist->data.list.elements[0] = create_float_node(6.0);
    subsublist->data.list.elements[1] = create_float_node(7.0);
    sublist2->data.list.elements[1] = subsublist;
    test_data->data.list.elements[3] = sublist2;
    test_data->data.list.elements[4] = create_float_node(8.0);

    char *result = lint_ast(test_data);
    printf("%s\n", result);
    free(result);
    free_node(test_data);
}