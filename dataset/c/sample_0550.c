#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
} Transformer;

void Transformer_init(Transformer* self) {
    self->data = NULL;
    self->size = 0;
}

void Transformer_transform(Transformer* self, int** points, int size, int** transformed) {
    *transformed = (int*)malloc(size * 3 * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*transformed)[i * 3] = points[i][0] + 1;
        (*transformed)[i * 3 + 1] = points[i][1] + 1;
        (*transformed)[i * 3 + 2] = points[i][2] + 1;
    }
}

typedef struct {
    int* errors;
    int size;
} Validator;

void Validator_init(Validator* self) {
    self->errors = NULL;
    self->size = 0;
}

int Validator_validate(Validator* self, int** points, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            if (!points[i][j]) {
                self->errors = (int*)realloc(self->errors, (self->size + 1) * 3 * sizeof(int));
                self->errors[self->size * 3] = points[i][0];
                self->errors[self->size * 3 + 1] = points[i][1];
                self->errors[self->size * 3 + 2] = points[i][2];
                self->size++;
            }
        }
    }
    return self->size == 0;
}

typedef struct {
    Transformer transformer;
    Validator validator;
} Processor;

void Processor_init(Processor* self) {
    Transformer_init(&self->transformer);
    Validator_init(&self->validator);
}

int** Processor_process(Processor* self, int** points, int size, int* result_size) {
    if (Validator_validate(&self->validator, points, size)) {
        int** transformed;
        Transformer_transform(&self->transformer, points, size, &transformed);
        *result_size = size;
        return transformed;
    } else {
        *result_size = 0;
        return NULL;
    }
}

int main() {
    Processor processor;
    Processor_init(&processor);
    int points[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int size = sizeof(points) / sizeof(points[0]);
    while (1) {
        int result_size;
        int** result = Processor_process(&processor, points, size, &result_size);
        if (result) {
            points = result;
            size = result_size;
        }
    }
    return 0;
}