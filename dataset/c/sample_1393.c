#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* key;
    void* value;
} DictEntry;

typedef struct {
    DictEntry* entries;
    int size;
} Dict;

typedef struct {
    void** items;
    int size;
} List;

bool is_string(void* node) {
    return node != NULL && *(char*)node != '\0';
}

void process_node(void* node) {
    if (node == NULL) return;

    if (node->items != NULL) { // Assuming node is a List
        List* list = (List*)node;
        for (int i = 0; i < list->size; i++) {
            process_node(list->items[i]);
        }
    } else if (node->entries != NULL) { // Assuming node is a Dict
        Dict* dict = (Dict*)node;
        for (int i = 0; i < dict->size; i++) {
            process_node(dict->entries[i].value);
        }
    } else {
        lint_node(node);
    }
}

void lint_node(void* node) {
    if (!is_string(node)) {
        fprintf(stderr, "Node must be a string\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Example data structure
    List* inner_list = (List*)malloc(sizeof(List));
    inner_list->items = (void**)malloc(2 * sizeof(void*));
    inner_list->size = 2;
    inner_list->items[0] = strdup("b");

    Dict* inner_dict = (Dict*)malloc(sizeof(Dict));
    inner_dict->entries = (DictEntry*)malloc(1 * sizeof(DictEntry));
    inner_dict->size = 1;
    inner_dict->entries[0].key = strdup("c");
    inner_dict->entries[0].value = strdup("d");

    inner_list->items[1] = inner_dict;

    Dict* data = (Dict*)malloc(sizeof(Dict));
    data->entries = (DictEntry*)malloc(2 * sizeof(DictEntry));
    data->size = 2;
    data->entries[0].key = strdup("a");
    data->entries[0].value = inner_list;

    data->entries[1].key = strdup("e");
    data->entries[1].value = strdup("f");

    process_node(data);

    // Cleanup (not implemented for brevity)
    return 0;
}