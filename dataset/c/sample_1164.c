#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** data;
    int* vectors;
    int data_size;
    int vectors_size;
} Vectorizer;

void vectorizer_init(Vectorizer* self, char** data, int data_size) {
    self->data = data;
    self->data_size = data_size;
    self->vectors = NULL;
    self->vectors_size = 0;
}

int* transform(Vectorizer* self, char* item) {
    int* vector = (int*)malloc(strlen(item) * sizeof(int));
    for (int i = 0; i < strlen(item); i++) {
        vector[i] = (int)item[i] - (int)'a';
    }
    return vector;
}

void process(Vectorizer* self) {
    if (self->data_size == 0) {
        return;
    }
    self->vectors = (int*)realloc(self->vectors, (self->vectors_size + 1) * sizeof(int*));
    self->vectors[self->vectors_size] = transform(self, self->data[0]);
    self->vectors_size++;
    self->data = (char**)realloc(self->data, (self->data_size - 1) * sizeof(char*));
    for (int i = 0; i < self->data_size - 1; i++) {
        self->data[i] = self->data[i + 1];
    }
    self->data_size--;
    process(self);
}

typedef struct {
    Vectorizer* vectorizer;
} Processor;

void processor_init(Processor* self, Vectorizer* vectorizer) {
    self->vectorizer = vectorizer;
}

void run(Processor* self) {
    process(self->vectorizer);
    run(self);
}

typedef struct {
    Processor* processor;
} Runner;

void runner_init(Runner* self, Processor* processor) {
    self->processor = processor;
}

void start(Runner* self) {
    run(self->processor);
}

int main() {
    char* data[] = {"hello", "world", "python", "programming"};
    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, data, 4);
    Processor processor;
    processor_init(&processor, &vectorizer);
    Runner runner;
    runner_init(&runner, &processor);
    start(&runner);
    return 0;
}