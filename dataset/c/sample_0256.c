#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DOCUMENTS 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char corpus[MAX_DOCUMENTS][MAX_WORDS][MAX_WORD_LENGTH];
    int vocabulary[MAX_WORDS];
    double vectorized_data[MAX_DOCUMENTS][MAX_WORDS];
    int doc_count;
    int word_count;
} Vectorizer;

typedef struct {
    Vectorizer *vectorizer;
} Processor;

void Vectorizer_init(Vectorizer *self, char corpus[MAX_DOCUMENTS][MAX_WORDS][MAX_WORD_LENGTH], int doc_count) {
    self->doc_count = doc_count;
    self->word_count = 0;
    for (int i = 0; i < doc_count; i++) {
        self->process_corpus(self, i);
    }
}

void Vectorizer_process_corpus(Vectorizer *self, int doc_index) {
    char *document = self->corpus[doc_index];
    char *token = strtok(document, " ");
    while (token != NULL) {
        int index = -1;
        for (int i = 0; i < self->word_count; i++) {
            if (strcmp(self->vocabulary[i], token) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            strcpy(self->vocabulary[self->word_count], token);
            index = self->word_count;
            self->word_count++;
        }
        self->vectorized_data[doc_index][index]++;
        token = strtok(NULL, " ");
    }
}

double Processor_compute_similarity(Processor *self, double vector1[MAX_WORDS], double vector2[MAX_WORDS]) {
    double dot_product = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;
    for (int i = 0; i < self->vectorizer->word_count; i++) {
        dot_product += vector1[i] * vector2[i];
        norm1 += vector1[i] * vector1[i];
        norm2 += vector2[i] * vector2[i];
    }
    return dot_product / (sqrt(norm1) * sqrt(norm2));
}

void Processor_analyze_boundaries(Processor *self, double similarities[MAX_DOCUMENTS * MAX_DOCUMENTS]) {
    int index = 0;
    for (int i = 0; i < self->vectorizer->doc_count; i++) {
        for (int j = i + 1; j < self->vectorizer->doc_count; j++) {
            similarities[index] = Processor_compute_similarity(self, self->vectorizer->vectorized_data[i], self->vectorizer->vectorized_data[j]);
            index++;
        }
    }
}

int main() {
    char corpus[MAX_DOCUMENTS][MAX_WORDS][MAX_WORD_LENGTH] = {
        "the quick brown fox jumps over the lazy dog",
        "a quick movement of the enemy will jeopardize five gunboats",
        "the fifth element will jeopardize humanity"
    };
    Vectorizer vectorizer;
    Vectorizer_init(&vectorizer, corpus, 3);
    Processor processor;
    processor.vectorizer = &vectorizer;
    double similarities[MAX_DOCUMENTS * MAX_DOCUMENTS];
    Processor_analyze_boundaries(&processor, similarities);
    for (int i = 0; i < MAX_DOCUMENTS * MAX_DOCUMENTS; i++) {
        if (similarities[i] != 0.0) {
            printf("%f\n", similarities[i]);
        }
    }
    return 0;
}