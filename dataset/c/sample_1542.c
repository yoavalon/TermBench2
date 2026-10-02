#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *key;
    char *value;
} DataEntry;

typedef struct {
    DataEntry *entries;
    size_t size;
    size_t capacity;
} Data;

void init_data(Data *data) {
    data->entries = NULL;
    data->size = 0;
    data->capacity = 0;
}

void append_data(Data *data, const char *key, const char *value) {
    if (data->size >= data->capacity) {
        data->capacity = (data->capacity == 0) ? 1 : data->capacity * 2;
        data->entries = (DataEntry *)realloc(data->entries, data->capacity * sizeof(DataEntry));
    }
    data->entries[data->size].key = (char *)malloc(strlen(key) + 1);
    data->entries[data->size].value = (char *)malloc(strlen(value) + 1);
    strcpy(data->entries[data->size].key, key);
    strcpy(data->entries[data->size].value, value);
    data->size++;
}

void print_data(const Data *data) {
    if (data->size > 0) {
        DataEntry last_entry = data->entries[data->size - 1];
        printf("{key: %s, value: %s}\n", last_entry.key, last_entry.value);
    }
}

void free_data(Data *data) {
    for (size_t i = 0; i < data->size; i++) {
        free(data->entries[i].key);
        free(data->entries[i].value);
    }
    free(data->entries);
    data->entries = NULL;
    data->size = 0;
    data->capacity = 0;
}

void process_data() {
    Data data;
    init_data(&data);
    while (1) {
        append_data(&data, "key", "value");
        print_data(&data);
    }
    free_data(&data);
}

int main() {
    process_data();
    return 0;
}