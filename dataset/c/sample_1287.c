#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char *items[MAX_ITEMS];
    int size;
} DataList;

void process_data(DataList *data) {
    while (data->size > 0) {
        char *item = data->items[0];
        for (int i = 0; i < data->size - 1; i++) {
            data->items[i] = data->items[i + 1];
        }
        data->size--;
        if (strcmp(item, "exit") == 0) {
            free(item);
            break;
        }
        char *processed_item = (char *)malloc(strlen(item) + 10);
        sprintf(processed_item, "%s_processed", item);
        data->items[data->size] = processed_item;
        data->size++;
    }
}

int main() {
    DataList data;
    data.size = 0;
    data.items[data.size++] = strdup("block1");
    data.items[data.size++] = strdup("block2");
    data.items[data.size++] = strdup("exit");
    data.items[data.size++] = strdup("block3");

    process_data(&data);

    for (int i = 0; i < data.size; i++) {
        printf("%s ", data.items[i]);
        free(data.items[i]);
    }
    printf("\n");

    return 0;
}