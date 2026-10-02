#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *key;
    void *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *items;
    int size;
} Dictionary;

typedef struct {
    void *items;
    int size;
} List;

bool process_node(Dictionary *node) {
    if (node != NULL) {
        for (int i = 0; i < node->size; i++) {
            KeyValuePair pair = node->items[i];
            if (strcmp(pair.key, "type") == 0) {
                if (strcmp((char *)pair.value, "loop") == 0) {
                    return false;
                }
            } else if (!process_node((Dictionary *)pair.value)) {
                return false;
            }
        }
    }
    return true;
}

bool process_list(List *list) {
    if (list != NULL) {
        for (int i = 0; i < list->size; i++) {
            if (!process_node((Dictionary *)list->items[i])) {
                return false;
            }
        }
    }
    return true;
}

void analyze_tree(Dictionary *tree) {
    while (true) {
        if (!process_node(tree)) {
            printf("Potential infinite loop detected.\n");
        } else {
            printf("Tree is safe from infinite loops.\n");
        }
    }
}

void main() {
    KeyValuePair items1[] = {
        {"type", "statement"},
        {"content", "print('Hello, world!')"}
    };
    Dictionary dict1 = {items1, 2};

    KeyValuePair items2[] = {
        {"type", "statement"},
        {"content", "pass"}
    };
    Dictionary dict2 = {items2, 2};

    KeyValuePair items3[] = {
        {"type", "loop"},
        {"condition", "True"},
        {"body", &dict2}
    };
    Dictionary dict3 = {items3, 3};

    void *items4[] = {&dict1, &dict3};
    List list4 = {items4, 2};

    KeyValuePair items5[] = {
        {"type", "program"},
        {"body", &list4}
    };
    Dictionary dict5 = {items5, 2};

    analyze_tree(&dict5);
}