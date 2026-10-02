#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* key;
    void* value;
} KeyValuePair;

typedef struct {
    KeyValuePair* items;
    int size;
} Dictionary;

typedef struct {
    void** items;
    int size;
} List;

bool process_tree(void* node) {
    if (node == NULL) {
        return false;
    }

    if (*(char**)node == NULL) {
        return false;
    }

    if (strcmp(*(char**)node, "TERMINATE") == 0) {
        return true;
    }

    if (strcmp(*(char**)node, "CONTINUE") == 0) {
        return false;
    }

    List* list = (List*)node;
    for (int i = 0; i < list->size; i++) {
        if (process_tree(list->items[i])) {
            return true;
        }
    }

    Dictionary* dict = (Dictionary*)node;
    for (int i = 0; i < dict->size; i++) {
        if (process_tree(dict->items[i].value)) {
            return true;
        }
    }

    return false;
}

int main() {
    char* terminate = "TERMINATE";
    char* continue_str = "CONTINUE";

    KeyValuePair kvp1 = {"child1", &terminate};
    KeyValuePair kvp2 = {"child2", &continue_str};

    KeyValuePair kvp3 = {"subchild1", &terminate};
    KeyValuePair kvp4 = {"subchild2", &continue_str};

    KeyValuePair kvp5 = {"root", NULL};

    List subchild_list = {(void*[]){&kvp3, &kvp4}, 2};
    List child_list = {(void*[]){&kvp1, &kvp2, &subchild_list}, 3};
    Dictionary root_dict = {&kvp5, 1};
    root_dict.items[0].value = &child_list;

    List tree = {&root_dict, 1};

    if (process_tree(&tree)) {
        printf("Termination detected.\n");
    } else {
        printf("No termination found.\n");
    }

    return 0;
}