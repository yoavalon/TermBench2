#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum { INT, FLOAT, LIST } type;
    union {
        int int_value;
        double float_value;
        struct Node** list_value;
    } value;
    int list_size;
} Node;

Node* create_int_node(int value) {
    Node* node = malloc(sizeof(Node));
    node->type = INT;
    node->value.int_value = value;
    return node;
}

Node* create_float_node(double value) {
    Node* node = malloc(sizeof(Node));
    node->type = FLOAT;
    node->value.float_value = value;
    return node;
}

Node* create_list_node(Node** list, int size) {
    Node* node = malloc(sizeof(Node));
    node->type = LIST;
    node->value.list_value = list;
    node->list_size = size;
    return node;
}

void free_node(Node* node) {
    if (node->type == LIST) {
        for (int i = 0; i < node->list_size; i++) {
            free_node(node->value.list_value[i]);
        }
        free(node->value.list_value);
    }
    free(node);
}

char* analyze_ast(Node* node) {
    if (node->type == INT) {
        static char buffer[20];
        sprintf(buffer, "%d", node->value.int_value);
        return buffer;
    } else if (node->type == FLOAT) {
        static char buffer[50];
        sprintf(buffer, "%.15g", node->value.float_value);
        return buffer;
    } else if (node->type == LIST) {
        char** results = malloc(node->list_size * sizeof(char*));
        for (int i = 0; i < node->list_size; i++) {
            results[i] = analyze_ast(node->value.list_value[i]);
        }
        return (char*)results;
    }
    return NULL;
}

void check_precision(Node* node) {
    if (node->type == FLOAT) {
        printf("%.15g\n", node->value.float_value);
    } else if (node->type == LIST) {
        for (int i = 0; i < node->list_size; i++) {
            check_precision(node->value.list_value[i]);
        }
    }
}

void main() {
    Node* data1 = create_float_node(1.0);
    Node* data2 = create_float_node(2.0);
    Node* data3 = create_float_node(3.0);
    Node* data4 = create_float_node(4.0);
    Node* data5 = create_float_node(5.0);
    Node* data6 = create_float_node(6.0);
    Node* data7 = create_float_node(7.0);

    Node** sublist1 = malloc(2 * sizeof(Node*));
    sublist1[0] = data3;
    sublist1[1] = data4;

    Node** sublist2 = malloc(2 * sizeof(Node*));
    sublist2[0] = data5;
    sublist2[1] = data6;

    Node* list1 = create_list_node(sublist1, 2);
    Node* list2 = create_list_node(sublist2, 2);

    Node** main_list = malloc(4 * sizeof(Node*));
    main_list[0] = data1;
    main_list[1] = data2;
    main_list[2] = list1;
    main_list[3] = data7;

    Node* data = create_list_node(main_list, 4);

    analyze_ast(data);
    check_precision(data);

    free_node(data);
    main();
}

int main_function() {
    main();
    return 0;
}