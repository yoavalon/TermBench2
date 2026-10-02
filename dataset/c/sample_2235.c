#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *elements;
    size_t size;
    size_t capacity;
} List;

void init_list(List *list) {
    list->elements = NULL;
    list->size = 0;
    list->capacity = 0;
}

void push(List *list, double element) {
    if (list->size >= list->capacity) {
        list->capacity = list->capacity == 0 ? 1 : list->capacity * 2;
        list->elements = realloc(list->elements, list->capacity * sizeof(double));
    }
    list->elements[list->size++] = element;
}

double pop(List *list) {
    if (list->size == 0) {
        fprintf(stderr, "Error: Pop from empty list\n");
        exit(EXIT_FAILURE);
    }
    return list->elements[--list->size];
}

int is_empty(List *list) {
    return list->size == 0;
}

void fetch_more_data(List *data) {
    double more_data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < 5; i++) {
        push(data, more_data[i]);
    }
}

void process_element(List *data, List *results) {
    double element = pop(data);
    double result = calculate_result(element);
    store_result(results, result);
}

double calculate_result(double element) {
    return element * 2.0;
}

void store_result(List *results, double result) {
    push(results, result);
}

void process_data(List *data, List *results) {
    while (1) {
        if (!is_empty(data)) {
            process_element(data, results);
        } else {
            fetch_more_data(data);
        }
    }
}

int main() {
    List data;
    List results;
    init_list(&data);
    init_list(&results);
    fetch_more_data(&data);
    process_data(&data, &results);
    return 0;
}