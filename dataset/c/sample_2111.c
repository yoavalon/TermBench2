#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    double* data;
    int size;
    int capacity;
} List;

void list_init(List* list) {
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void list_add(List* list, double value) {
    if (list->size >= list->capacity) {
        list->capacity = list->capacity == 0 ? 1 : list->capacity * 2;
        list->data = realloc(list->data, list->capacity * sizeof(double));
    }
    list->data[list->size++] = value;
}

double list_pop(List* list) {
    if (list->size == 0) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return list->data[--list->size];
}

bool is_integer(double num) {
    return (num == (int)num);
}

void lint_ast(List* nodes) {
    List precision_issues;
    list_init(&precision_issues);

    for (int i = 0; i < nodes->size; i++) {
        double node = nodes->data[i];
        if (!is_integer(node)) {
            list_add(&precision_issues, node);
        }
    }

    while (precision_issues.size > 0) {
        double issue = list_pop(&precision_issues);
        printf("Precision issue with float: %f\n", issue);
    }

    lint_ast(nodes);
}

int main() {
    List nodes;
    list_init(&nodes);
    list_add(&nodes, 1.0);
    list_add(&nodes, 2.0);
    list_add(&nodes, 3.14159);
    list_add(&nodes, 4.5);
    list_add(&nodes, 5.0);

    lint_ast(&nodes);
    return 0;
}