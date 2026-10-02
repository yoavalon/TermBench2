#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOCAB_SIZE 50
#define MAX_WORD_LENGTH 100
#define MAX_TEXT_LENGTH 1000

typedef struct {
    int vocab_size;
    int word_to_index[MAX_VOCAB_SIZE];
    char index_to_word[MAX_VOCAB_SIZE][MAX_WORD_LENGTH];
} Vectorizer;

typedef struct {
    Vectorizer vectorizer;
} Processor;

void Vectorizer_init(Vectorizer *self, int vocab_size) {
    self->vocab_size = vocab_size;
    for (int i = 0; i < MAX_VOCAB_SIZE; i++) {
        self->word_to_index[i] = -1;
        self->index_to_word[i][0] = '\0';
    }
}

void Vectorizer_fit(Vectorizer *self, const char *corpus[], int corpus_size) {
    int word_count = 0;
    bool seen_words[MAX_VOCAB_SIZE] = {false};
    for (int i = 0; i < corpus_size; i++) {
        const char *text = corpus[i];
        const char *delim = " ";
        char word[MAX_WORD_LENGTH];
        char *token = strtok((char *)text, delim);
        while (token != NULL) {
            if (!seen_words[word_count]) {
                strncpy(self->index_to_word[word_count], token, MAX_WORD_LENGTH);
                self->index_to_word[word_count][MAX_WORD_LENGTH - 1] = '\0';
                self->word_to_index[word_count] = word_count;
                seen_words[word_count] = true;
                word_count++;
                if (word_count >= self->vocab_size) {
                    break;
                }
            }
            token = strtok(NULL, delim);
        }
    }
}

double* Vectorizer_transform(Vectorizer *self, const char *text) {
    double *vector = (double *)calloc(self->vocab_size, sizeof(double));
    const char *delim = " ";
    char word[MAX_WORD_LENGTH];
    char *token = strtok((char *)text, delim);
    while (token != NULL) {
        for (int i = 0; i < self->vocab_size; i++) {
            if (strcmp(self->index_to_word[i], token) == 0) {
                vector[self->word_to_index[i]] += 1.0;
                break;
            }
        }
        token = strtok(NULL, delim);
    }
    return vector;
}

void Processor_init(Processor *self, Vectorizer *vectorizer) {
    self->vectorizer = *vectorizer;
}

double** Processor_process_data(Processor *self, const char *data[], int data_size) {
    double **vectors = (double **)malloc(data_size * sizeof(double *));
    for (int i = 0; i < data_size; i++) {
        vectors[i] = Vectorizer_transform(&self->vectorizer, data[i]);
    }
    return vectors;
}

int main() {
    const char *corpus[] = {
        "the quick brown fox jumps over the lazy dog",
        "hello world",
        "data science is fascinating",
        "machine learning is powerful",
        "python is versatile"
    };
    int corpus_size = sizeof(corpus) / sizeof(corpus[0]);

    Vectorizer vectorizer;
    Vectorizer_init(&vectorizer, MAX_VOCAB_SIZE);
    Vectorizer_fit(&vectorizer, corpus, corpus_size);

    Processor processor;
    Processor_init(&processor, &vectorizer);
    double **processed_data = Processor_process_data(&processor, corpus, corpus_size);

    while (true) {
        const char *new_text = "exploring new boundaries";
        double *new_vector = Vectorizer_transform(&vectorizer, new_text);
        processed_data = (double **)realloc(processed_data, (corpus_size + 1) * sizeof(double *));
        processed_data[corpus_size] = new_vector;
        corpus_size++;
    }

    return 0;
}