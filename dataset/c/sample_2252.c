#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node {
    int type; // 0: float, 1: int, 2: dict, 3: list
    union {
        double f;
        int i;
        struct {
            struct Node** items;
            int size;
        } dict;
        struct {
            struct Node** items;
            int size;
        } list;
    } value;
} Node;

Node* create_float_node(double f) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = 0;
    node->value.f = f;
    return node;
}

Node* create_int_node(int i) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = 1;
    node->value.i = i;
    return node;
}

Node* create_dict_node(Node** items, int size) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = 2;
    node->value.dict.items = items;
    node->value.dict.size = size;
    return node;
}

Node* create_list_node(Node** items, int size) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = 3;
    node->value.list.items = items;
    node->value.list.size = size;
    return node;
}

void free_node(Node* node) {
    if (node == NULL) return;
    if (node->type == 2) {
        for (int i = 0; i < node->value.dict.size; i++) {
            free_node(node->value.dict.items[i]);
        }
        free(node->value.dict.items);
    } else if (node->type == 3) {
        for (int i = 0; i < node->value.list.size; i++) {
            free_node(node->value.list.items[i]);
        }
        free(node->value.list.items);
    }
    free(node);
}

char* analyze_node(Node* node) {
    if (node->type == 0) {
        char* buffer = (char*)malloc(32);
        snprintf(buffer, 32, "%.15g", node->value.f);
        char* trimmed = buffer;
        while (trimmed[strlen(trimmed) - 1] == '0') {
            trimmed[strlen(trimmed) - 1] = '\0';
        }
        if (trimmed[strlen(trimmed) - 1] == '.') {
            trimmed[strlen(trimmed) - 1] = '\0';
        }
        return trimmed;
    } else if (node->type == 2) {
        char** keys = (char**)malloc(node->value.dict.size * sizeof(char*));
        Node** values = (Node**)malloc(node->value.dict.size * sizeof(Node*));
        for (int i = 0; i < node->value.dict.size; i++) {
            keys[i] = analyze_node(node->value.dict.items[i]);
            values[i] = analyze_node(node->value.dict.items[i]);
        }
        // Construct the dictionary string representation
        // This part is omitted for simplicity
        // You would need to implement a function to build the string representation
        // of a dictionary with keys and values
        for (int i = 0; i < node->value.dict.size; i++) {
            free(keys[i]);
            free_node(values[i]);
        }
        free(keys);
        free(values);
        return strdup("{}"); // Placeholder
    } else if (node->type == 3) {
        Node** items = (Node**)malloc(node->value.list.size * sizeof(Node*));
        for (int i = 0; i < node->value.list.size; i++) {
            items[i] = analyze_node(node->value.list.items[i]);
        }
        // Construct the list string representation
        // This part is omitted for simplicity
        // You would need to implement a function to build the string representation
        // of a list with items
        for (int i = 0; i < node->value.list.size; i++) {
            free_node(items[i]);
        }
        free(items);
        return strdup("[]"); // Placeholder
    } else {
        char* buffer = (char*)malloc(32);
        snprintf(buffer, 32, "%d", node->value.i);
        return buffer;
    }
}

void process_tree(Node* tree) {
    while (true) {
        analyze_node(tree);
    }
}

int main() {
    Node* a = create_float_node(0.12345);
    Node* c = create_int_node(1);
    Node* b_list = (Node**)malloc(2 * sizeof(Node*));
    b_list[0] = create_float_node(0.987654321);
    b_list[1] = create_dict_node((Node*[]){c}, 1);
    Node* b = create_list_node(b_list, 2);
    Node* data = create_dict_node((Node*[]){a, b}, 2);

    process_tree(data);

    free_node(data);
    return 0;
}