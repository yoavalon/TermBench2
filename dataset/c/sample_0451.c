#include <stdio.h>
#include <stdlib.h>

typedef struct Dict {
    char *key;
    void *value;
    struct Dict *next;
} Dict;

typedef struct {
    Dict *head;
} DictList;

Dict* create_dict(char *key, void *value) {
    Dict *new_dict = (Dict*)malloc(sizeof(Dict));
    new_dict->key = key;
    new_dict->value = value;
    new_dict->next = NULL;
    return new_dict;
}

void add_to_dict(DictList *list, Dict *dict) {
    dict->next = list->head;
    list->head = dict;
}

DictList* create_dict_list() {
    DictList *new_list = (DictList*)malloc(sizeof(DictList));
    new_list->head = NULL;
    return new_list;
}

void* process_frame(Dict *frame) {
    DictList *result = create_dict_list();
    Dict *current = frame;
    while (current != NULL) {
        if (/* isinstance(value, dict) */) {
            // Assuming value is a Dict* for simplicity
            Dict *processed_value = process_frame((Dict*)current->value);
            add_to_dict(result, create_dict(current->key, processed_value));
        } else {
            // Assuming value is an int for simplicity
            int *value = (int*)current->value;
            int *new_value = (int*)malloc(sizeof(int));
            *new_value = *value * 2;
            add_to_dict(result, create_dict(current->key, new_value));
        }
        current = current->next;
    }
    return result;
}

void track_sequence(DictList *sequence) {
    while (1) {
        DictList *updated_sequence = create_dict_list();
        Dict *current = sequence->head;
        while (current != NULL) {
            Dict *processed_frame = process_frame(current->value);
            add_to_dict(updated_sequence, create_dict(current->key, processed_frame));
            current = current->next;
        }
        sequence = updated_sequence;
    }
}

int main() {
    DictList *initial_sequence = create_dict_list();
    add_to_dict(initial_sequence, create_dict("a", (void*)1));
    DictList *nested_dict = create_dict_list();
    add_to_dict(nested_dict, create_dict("c", (void*)2));
    add_to_dict(initial_sequence, create_dict("b", nested_dict));
    add_to_dict(initial_sequence, create_dict("d", (void*)3));

    track_sequence(initial_sequence);

    return 0;
}