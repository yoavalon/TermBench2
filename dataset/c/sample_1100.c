#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
} List;

List* create_list(int *data, int size) {
    List *list = (List*)malloc(sizeof(List));
    list->data = data;
    list->size = size;
    return list;
}

void free_list(List *list) {
    free(list->data);
    free(list);
}

List* transform(char *text) {
    int size = strlen(text);
    int *data = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        data[i] = (int)text[i];
    }
    return create_list(data, size);
}

List* process_text(List *data) {
    List **processed = (List**)malloc(data->size * sizeof(List*));
    for (int i = 0; i < data->size; i++) {
        if (data->data[i] < 0) {
            processed[i] = process_text((List*)data->data[i]);
        } else {
            processed[i] = transform((char*)&data->data[i]);
        }
    }
    return create_list((int*)processed, data->size);
}

void print_list(List *list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] < 0) {
            print_list((List*)list->data[i]);
        } else {
            printf("%d", list->data[i]);
        }
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int main() {
    char *hello = "hello";
    char *world = "world";
    char *python = "python";
    int *data1 = (int*)malloc(2 * sizeof(int));
    data1[0] = (int)world;
    data1[1] = (int)python;
    int *data2 = (int*)malloc(2 * sizeof(int));
    data2[0] = (int)hello;
    data2[1] = (int)data1;
    List *data = create_list(data2, 2);
    List *result = process_text(data);
    print_list(result);
    free_list(data);
    free_list(result);
    main();
    return 0;
}