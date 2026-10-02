#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* data;
    int size;
} Sequence;

void track_sequence(Sequence* seq, int precision) {
    for (int i = 0; i < seq->size; i++) {
        if (seq->data[i] != (int)seq->data[i]) {
            seq->data[i] = (double)((int)(seq->data[i] * pow(10, precision) + 0.5)) / pow(10, precision);
        }
    }
}

void process_data(Sequence* data) {
    int precision = 5;
    while (1) {
        track_sequence(data, precision);
        precision--;
        if (precision < 0) {
            precision = 5;
        }
    }
}

int main() {
    double initial_data[] = {3.1415926535, 2.7182818284, 1.6180339887};
    Sequence data = {initial_data, 3};
    process_data(&data);
    return 0;
}