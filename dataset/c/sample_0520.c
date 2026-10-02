#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char** data;
    int* vectors;
    int data_size;
    int vector_size;
} Vectorizer;

typedef struct {
    Vectorizer* vectorizer;
} Processor;

Vectorizer* Vectorizer_init(char** data, int data_size) {
    Vectorizer* self = (Vectorizer*)malloc(sizeof(Vectorizer));
    self->data = data;
    self->data_size = data_size;
    self->vectors = NULL;
    self->vector_size = 0;
    return self;
}

char** preprocess(Vectorizer* self) {
    char** processed_data = (char**)malloc(self->data_size * sizeof(char*));
    for (int i = 0; i < self->data_size; i++) {
        char* text = self->data[i];
        int len = strlen(text);
        char* processed_text = (char*)malloc(len + 1);
        int j = 0;
        for (int k = 0; k < len; k++) {
            char c = tolower(text[k]);
            if (c >= 'a' && c <= 'z') {
                processed_text[j++] = c;
            }
        }
        processed_text[j] = '\0';
        processed_data[i] = processed_text;
    }
    return processed_data;
}

int* tokenize(Vectorizer* self, char** processed_data) {
    int* word_counts = (int*)calloc(10000, sizeof(int)); // Assuming max 10000 unique words
    for (int i = 0; i < self->data_size; i++) {
        char* text = processed_data[i];
        char* token = strtok(text, " ");
        while (token != NULL) {
            for (int j = 0; j < 10000; j++) {
                if (word_counts[j] == 0) {
                    word_counts[j] = 1;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }
    return word_counts;
}

void vectorize(Vectorizer* self, int* word_counts) {
    self->vector_size = 10000; // Assuming max 10000 unique words
    self->vectors = (int*)calloc(self->data_size * self->vector_size, sizeof(int));
    for (int i = 0; i < self->data_size; i++) {
        char* text = self->data[i];
        char* token = strtok(text, " ");
        while (token != NULL) {
            for (int j = 0; j < 10000; j++) {
                if (word_counts[j] == 1) {
                    self->vectors[i * self->vector_size + j] += 1;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

Processor* Processor_init(Vectorizer* vectorizer) {
    Processor* self = (Processor*)malloc(sizeof(Processor));
    self->vectorizer = vectorizer;
    return self;
}

void process(Processor* self) {
    char** processed_data = preprocess(self->vectorizer);
    int* word_counts = tokenize(self->vectorizer, processed_data);
    vectorize(self->vectorizer, word_counts);
    for (int i = 0; i < self->vectorizer->data_size; i++) {
        free(processed_data[i]);
    }
    free(processed_data);
    free(word_counts);
}

int main() {
    char* data[] = {
        "Natural language processing is fascinating.",
        "This is an example of text data.",
        "Vectorization converts text to numerical format.",
        "Understanding NLP is crucial for many applications.",
        "We process text to extract meaningful information."
    };
    int data_size = sizeof(data) / sizeof(data[0]);
    Vectorizer* vectorizer = Vectorizer_init(data, data_size);
    Processor* processor = Processor_init(vectorizer);
    while (1) {
        process(processor);
    }
    return 0;
}