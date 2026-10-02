#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VEC_SIZE 26
#define SEQ_LENGTH 100

typedef struct {
    int vocab_size;
    int word_to_index[VEC_SIZE];
} Vectorizer;

void init_vectorizer(Vectorizer *vec, int vocab_size) {
    vec->vocab_size = vocab_size;
    for (int i = 0; i < vocab_size; i++) {
        vec->word_to_index[i] = i;
    }
}

int transform(Vectorizer *vec, char *text, int *output) {
    int index = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c < 'a' + vec->vocab_size) {
            output[index++] = vec->word_to_index[c - 'a'];
        }
    }
    return index;
}

typedef struct {
    Vectorizer *vectorizer;
} SequenceProcessor;

void init_sequence_processor(SequenceProcessor *sp, Vectorizer *vectorizer) {
    sp->vectorizer = vectorizer;
}

void generate_sequences(SequenceProcessor *sp, char sequences[SEQ_LENGTH][SEQ_LENGTH + 1], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            sequences[i][j] = 'a' + rand() % sp->vectorizer->vocab_size;
        }
        sequences[i][length] = '\0';
    }
}

typedef struct {
    SequenceProcessor *processor;
} Analysis;

void init_analysis(Analysis *a, SequenceProcessor *processor) {
    a->processor = processor;
}

void analyze(Analysis *a, char sequences[SEQ_LENGTH][SEQ_LENGTH + 1], int *counts, int length) {
    memset(counts, 0, sizeof(int) * VEC_SIZE * VEC_SIZE);
    for (int i = 0; i < length; i++) {
        int vector[SEQ_LENGTH];
        int vector_size = transform(a->processor->vectorizer, sequences[i], vector);
        if (vector_size == 2) {
            int index = vector[0] * VEC_SIZE + vector[1];
            counts[index]++;
        }
    }
}

int main() {
    int vocab_size = VEC_SIZE;
    Vectorizer vectorizer;
    init_vectorizer(&vectorizer, vocab_size);

    SequenceProcessor processor;
    init_sequence_processor(&processor, &vectorizer);

    Analysis analysis;
    init_analysis(&analysis, &processor);

    char sequences[SEQ_LENGTH][SEQ_LENGTH + 1];
    generate_sequences(&processor, sequences, SEQ_LENGTH);

    int counts[VEC_SIZE * VEC_SIZE];
    analyze(&analysis, sequences, counts, SEQ_LENGTH);

    for (int i = 0; i < VEC_SIZE; i++) {
        for (int j = 0; j < VEC_SIZE; j++) {
            int index = i * VEC_SIZE + j;
            if (counts[index] > 0) {
                printf("Vector: (%d, %d), Count: %d\n", i, j, counts[index]);
            }
        }
    }

    return 0;
}