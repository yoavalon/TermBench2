c
#include <stdio.h>

#define LENGTH 10

typedef struct {
    int length;
    double data[LENGTH];
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *sg, int length) {
    sg->length = length;
    for (int i = 0; i < length; i++) {
        sg->data[i] = 0;
    }
}

void SequenceGenerator_generate_fibonacci(SequenceGenerator *sg) {
    if (sg->length > 0) {
        sg->data[0] = 0;
    }
    if (sg->length > 1) {
        sg->data[1] = 1;
    }
    for (int i = 2; i < sg->length; i++) {
        sg->data[i] = sg->data[i - 1] + sg->data[i - 2];
    }
}

void SequenceGenerator_generate_harmonic(SequenceGenerator *sg) {
    for (int i = 0; i < sg->length; i++) {
        sg->data[i] = 1.0 / (i + 1);
    }
}

void SequenceGenerator_get_sequence(SequenceGenerator *sg, double *seq) {
    for (int i = 0; i < sg->length; i++) {
        seq[i] = sg->data[i];
    }
}

void process_sequence(double *seq, double *filtered_seq, int length) {
    for (int i = 0; i < length; i++) {
        filtered_seq[i] = (seq[i] > 0.5) ? seq[i] : 0;
    }
}

void analyze_sequence(double *seq, int length, double *mean, double *max_val, double *min_val) {
    double sum = 0;
    *max_val = seq[0];
    *min_val = seq[0];
    for (int i = 0; i < length; i++) {
        sum += seq[i];
        if (seq[i] > *max_val) {
            *max_val = seq[i];
        }
        if (seq[i] < *min_val) {
            *min_val = seq[i];
        }
    }
    *mean = sum / length;
}

int main() {
    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, LENGTH);
    SequenceGenerator_generate_fibonacci(&seq_gen);
    double seq[LENGTH];
    SequenceGenerator_get_sequence(&seq_gen, seq);
    double processed_seq[LENGTH];
    process_sequence(seq, processed_seq, LENGTH);
    double mean, max_val, min_val;
    analyze_sequence(processed_seq, LENGTH, &mean, &max_val, &min_val);
    printf("Mean: %f Max: %f Min: %f\n", mean, max_val, min_val);
    return 0;
}