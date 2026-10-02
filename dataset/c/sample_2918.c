#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** data;
    int length;
    int index;
} Vectorizer;

typedef struct {
    Vectorizer* vectorizer;
} SequenceProcessor;

typedef struct {
    SequenceProcessor* processor;
} OutputHandler;

Vectorizer* Vectorizer_new(char** data, int length) {
    Vectorizer* self = (Vectorizer*)malloc(sizeof(Vectorizer));
    self->data = data;
    self->length = length;
    self->index = 0;
    return self;
}

char* Vectorizer_process(Vectorizer* self) {
    if (self->index < self->length) {
        return self->data[self->index++];
    } else {
        self->index = 0;
        return self->data[self->index++];
    }
}

SequenceProcessor* SequenceProcessor_new(Vectorizer* vectorizer) {
    SequenceProcessor* self = (SequenceProcessor*)malloc(sizeof(SequenceProcessor));
    self->vectorizer = vectorizer;
    return self;
}

int* SequenceProcessor_transform(SequenceProcessor* self, int* length) {
    char* item = Vectorizer_process(self->vectorizer);
    if (item == NULL) return NULL;
    *length = strlen(item);
    int* vector = (int*)malloc(*length * sizeof(int));
    for (int i = 0; i < *length; i++) {
        vector[i] = (int)item[i];
    }
    return vector;
}

OutputHandler* OutputHandler_new(SequenceProcessor* processor) {
    OutputHandler* self = (OutputHandler*)malloc(sizeof(OutputHandler));
    self->processor = processor;
    return self;
}

void OutputHandler_display(OutputHandler* self) {
    int length;
    int* vector;
    while ((vector = SequenceProcessor_transform(self->processor, &length)) != NULL) {
        for (int i = 0; i < length; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");
        free(vector);
    }
}

void main() {
    char* data[] = {"hello", "world", "this", "is", "a", "test", "sequence"};
    int length = sizeof(data) / sizeof(data[0]);
    Vectorizer* vectorizer = Vectorizer_new(data, length);
    SequenceProcessor* processor = SequenceProcessor_new(vectorizer);
    OutputHandler* handler = OutputHandler_new(processor);
    OutputHandler_display(handler);
}