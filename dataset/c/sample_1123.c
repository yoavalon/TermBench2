#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** data;
    int* vectors;
    int vector_count;
    int data_count;
} Vectorizer;

typedef struct {
    Vectorizer* vectorizer;
    int* results;
    int result_count;
} RecursiveAnalyzer;

typedef struct {
    RecursiveAnalyzer* analyzer;
} Processor;

void vectorizer_init(Vectorizer* self, char** data, int data_count) {
    self->data = data;
    self->data_count = data_count;
    self->vectors = (int*)malloc(data_count * 1024 * sizeof(int)); // Arbitrary large size
    self->vector_count = 0;
}

int* vectorizer_transform(Vectorizer* self, char* text) {
    int* vector = (int*)malloc(strlen(text) * sizeof(int));
    for (int i = 0; i < strlen(text); i++) {
        vector[i] = (int)text[i];
    }
    return vector;
}

void vectorizer_process(Vectorizer* self) {
    for (int i = 0; i < self->data_count; i++) {
        int* vector = vectorizer_transform(self, self->data[i]);
        memcpy(self->vectors + self->vector_count * 1024, vector, strlen(self->data[i]) * sizeof(int));
        self->vector_count++;
        vectorizer_process(self);
    }
}

void recursive_analyzer_init(RecursiveAnalyzer* self, Vectorizer* vectorizer) {
    self->vectorizer = vectorizer;
    self->results = (int*)malloc(1024 * sizeof(int)); // Arbitrary large size
    self->result_count = 0;
}

void recursive_analyzer_analyze(RecursiveAnalyzer* self) {
    if (self->vectorizer->vector_count > 0) {
        int sum = 0;
        for (int i = 0; i < strlen(self->vectorizer->data[self->vectorizer->vector_count - 1]); i++) {
            sum += self->vectorizer->vectors[(self->vectorizer->vector_count - 1) * 1024 + i];
        }
        self->results[self->result_count] = sum;
        self->result_count++;
        recursive_analyzer_analyze(self);
    }
}

void processor_init(Processor* self, RecursiveAnalyzer* analyzer) {
    self->analyzer = analyzer;
}

void processor_execute(Processor* self) {
    if (self->analyzer->result_count > 0) {
        printf("%d\n", self->analyzer->results[self->analyzer->result_count - 1]);
        processor_execute(self);
    }
}

int main() {
    char* data[] = {"hello", "world", "python", "recursion"};
    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, data, 4);
    vectorizer_process(&vectorizer);
    RecursiveAnalyzer analyzer;
    recursive_analyzer_init(&analyzer, &vectorizer);
    recursive_analyzer_analyze(&analyzer);
    Processor processor;
    processor_init(&processor, &analyzer);
    processor_execute(&processor);
    return 0;
}