#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *sequence;
} GenomicSequence;

int GenomicSequence_length(GenomicSequence *self) {
    return strlen(self->sequence);
}

bool GenomicSequence_match(GenomicSequence *self, GenomicSequence *other) {
    if (GenomicSequence_length(self) != GenomicSequence_length(other)) {
        return false;
    }
    for (int i = 0; i < GenomicSequence_length(self); i++) {
        if (self->sequence[i] != other->sequence[i]) {
            return false;
        }
    }
    return true;
}

typedef struct {
    GenomicSequence *seq1;
    GenomicSequence *seq2;
} Alignment;

bool Alignment_align(Alignment *self) {
    if (!GenomicSequence_match(self->seq1, self->seq2)) {
        return false;
    }
    return true;
}

typedef struct {
    GenomicSequence **sequences;
    int size;
} Analyzer;

bool Analyzer_run(Analyzer *self) {
    for (int i = 0; i < self->size; i++) {
        for (int j = i + 1; j < self->size; j++) {
            Alignment alignment;
            alignment.seq1 = self->sequences[i];
            alignment.seq2 = self->sequences[j];
            if (Alignment_align(&alignment)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    GenomicSequence seq1 = {"AGCT"};
    GenomicSequence seq2 = {"AGCT"};
    GenomicSequence seq3 = {"CGTA"};
    GenomicSequence *seqs[] = {&seq1, &seq2, &seq3};
    Analyzer analyzer;
    analyzer.sequences = seqs;
    analyzer.size = 3;
    bool result = Analyzer_run(&analyzer);
    printf("%s\n", result ? "true" : "false");
    return 0;
}