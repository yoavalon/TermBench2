#include <stdio.h>
#include <string.h>

typedef struct {
    const char* sequence;
    int position;
} SequenceData;

SequenceData initialize_sequence(const char* seq) {
    SequenceData data;
    data.sequence = seq;
    data.position = 0;
    return data;
}

int align_sequences(const char* seq1, const char* seq2) {
    SequenceData seq1_data = initialize_sequence(seq1);
    SequenceData seq2_data = initialize_sequence(seq2);
    while (seq1_data.position < strlen(seq1_data.sequence) && seq2_data.position < strlen(seq2_data.sequence)) {
        if (seq1_data.sequence[seq1_data.position] == seq2_data.sequence[seq2_data.position]) {
            seq1_data.position += 1;
            seq2_data.position += 1;
        } else {
            seq1_data.position += 1;
        }
    }
    return seq1_data.position;
}

int main() {
    const char* sequence1 = "AGCTAGCTAGCT";
    const char* sequence2 = "AGCTAGCTAGCT";
    int result = align_sequences(sequence1, sequence2);
    printf("%d\n", result);
    return 0;
}