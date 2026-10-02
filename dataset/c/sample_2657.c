#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <setjmp.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_VOCABULARY_SIZE 100

typedef struct {
    char text[MAX_TEXT_LENGTH];
    char vocabulary[MAX_VOCABULARY_SIZE][MAX_WORD_LENGTH];
    int vector[MAX_VOCABULARY_SIZE];
    int vocabulary_count;
} Vectorizer;

typedef struct {
    Vectorizer vectorizer;
    int sequence[5][MAX_VOCABULARY_SIZE];
} Sequence;

typedef struct {
    Sequence sequence;
} Analyze;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void split_text(Vectorizer *self) {
    char *token = strtok(self->text, " ");
    self->vocabulary_count = 0;
    while (token && self->vocabulary_count < MAX_VOCABULARY_SIZE) {
        strcpy(self->vocabulary[self->vocabulary_count], token);
        self->vocabulary_count++;
        token = strtok(NULL, " ");
    }
}

void create_vector(Vectorizer *self) {
    for (int i = 0; i < self->vocabulary_count; i++) {
        self->vector[i] = 0;
    }
    char *temp_text = strdup(self->text);
    char *token = strtok(temp_text, " ");
    while (token) {
        for (int i = 0; i < self->vocabulary_count; i++) {
            if (strcmp(token, self->vocabulary[i]) == 0) {
                self->vector[i]++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    free(temp_text);
}

void generate_sequence(Sequence *self, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < self->vectorizer.vocabulary_count; j++) {
            self->sequence[i][j] = self->vectorizer.vector[j];
        }
    }
}

double calculate_entropy(Analyze *self) {
    int total_words = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < self->sequence.vectorizer.vocabulary_count; j++) {
            total_words += self->sequence.sequence[i][j];
        }
    }
    double entropy = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < self->sequence.vectorizer.vocabulary_count; j++) {
            if (self->sequence.sequence[i][j] > 0) {
                double probability = (double)self->sequence.sequence[i][j] / total_words;
                entropy -= probability * log2(probability);
            }
        }
    }
    return entropy;
}

int main() {
    Vectorizer vectorizer;
    strcpy(vectorizer.text, "Natural language processing vectorization involves converting text into numerical vectors");
    to_lowercase(vectorizer.text);
    split_text(&vectorizer);
    create_vector(&vectorizer);

    Sequence sequence;
    sequence.vectorizer = vectorizer;
    generate_sequence(&sequence, 5);

    Analyze analyze;
    analyze.sequence = sequence;
    double entropy = calculate_entropy(&analyze);

    printf("Entropy: %f\n", entropy);

    return 0;
}