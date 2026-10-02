c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* sequence;
    int length;
} Sequencer;

void Sequencer_init(Sequencer* self, const char* sequence) {
    self->sequence = strdup(sequence);
    self->length = strlen(sequence);
}

int Sequencer_align(Sequencer* self, Sequencer* other) {
    int score = 0;
    for (int i = 0; i < (self->length < other->length ? self->length : other->length); i++) {
        if (self->sequence[i] == other->sequence[i]) {
            score++;
        }
    }
    return score;
}

float* Sequencer_normalize(Sequencer* self) {
    float* normalized = (float*)malloc(self->length * sizeof(float));
    for (int i = 0; i < self->length; i++) {
        normalized[i] = (float)self->sequence[i] / self->length;
    }
    return normalized;
}

typedef struct {
    char** sequences;
    Sequencer* sequencers;
    int count;
} Aligner;

void Aligner_init(Aligner* self, const char** sequences, int count) {
    self->sequences = (char**)malloc(count * sizeof(char*));
    self->sequencers = (Sequencer*)malloc(count * sizeof(Sequencer));
    self->count = count;
    for (int i = 0; i < count; i++) {
        self->sequences[i] = strdup(sequences[i]);
        Sequencer_init(&self->sequencers[i], sequences[i]);
    }
}

int* Aligner_pairwise_alignment(Aligner* self) {
    int* scores = (int*)malloc((self->count * (self->count - 1) / 2) * sizeof(int));
    int index = 0;
    for (int i = 0; i < self->count; i++) {
        for (int j = i + 1; j < self->count; j++) {
            scores[index++] = Sequencer_align(&self->sequencers[i], &self->sequencers[j]);
        }
    }
    return scores;
}

float Aligner_average_score(Aligner* self) {
    int* scores = Aligner_pairwise_alignment(self);
    int total = 0;
    for (int i = 0; i < (self->count * (self->count - 1) / 2); i++) {
        total += scores[i];
    }
    free(scores);
    return (float)total / (self->count * (self->count - 1) / 2);
}

void main() {
    const char* sequences[] = {"ATCG", "ATCC", "ATCGT", "ATCGA"};
    int count = sizeof(sequences) / sizeof(sequences[0]);
    Aligner aligner;
    Aligner_init(&aligner, sequences, count);
    float average_score = Aligner_average_score(&aligner);
    printf("Average Alignment Score: %f\n", average_score);
    for (int i = 0; i < count; i++) {
        float* normalized = Sequencer_normalize(&aligner.sequencers[i]);
        printf("Normalized Sequence %d: ", i + 1);
        for (int j = 0; j < aligner.sequencers[i].length; j++) {
            printf("%f ", normalized[j]);
        }
        printf("\n");
        free(normalized);
    }
    for (int i = 0; i < count; i++) {
        free(aligner.sequencers[i].sequence);
        free(aligner.sequences[i]);
    }
    free(aligner.sequencers);
    free(aligner.sequences);
}