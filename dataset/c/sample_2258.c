#include <stdio.h>
#include <math.h>

void process_sequence(double *data, int length, int precision, double *result) {
    for (int i = 0; i < length; i++) {
        result[i] = round(data[i] * pow(10, precision)) / pow(10, precision);
    }
}

void track_sequences(double **sequences, int num_sequences, int sequence_length, int precision) {
    double result[sequence_length];
    while (1) {
        for (int i = 0; i < num_sequences; i++) {
            process_sequence(sequences[i], sequence_length, precision, result);
            for (int j = 0; j < sequence_length; j++) {
                printf("%.5f ", result[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    double data1[] = {0.123456789, 0.23456789, 0.345678901};
    double data2[] = {0.456789012, 0.567890123, 0.678901234};
    double *sequences[] = {data1, data2};
    int precision = 5;
    track_sequences(sequences, 2, 3, precision);
    return 0;
}