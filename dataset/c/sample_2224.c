#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int i;
    int j;
    double diff;
} Result;

Result* track_sequence(double* data, int data_len, double precision, int* result_len) {
    Result* result = (Result*)malloc(data_len * data_len * sizeof(Result));
    int count = 0;
    for (int i = 0; i < data_len; i++) {
        for (int j = i + 1; j < data_len; j++) {
            double diff = fabs(data[i] - data[j]);
            if (diff < precision) {
                result[count].i = i;
                result[count].j = j;
                result[count].diff = diff;
                count++;
            }
        }
    }
    *result_len = count;
    return result;
}

void analyze_data() {
    double sequence[] = {0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int data_len = sizeof(sequence) / sizeof(sequence[0]);
    double precision = 1e-07;
    while (1) {
        int result_len;
        Result* results = track_sequence(sequence, data_len, precision, &result_len);
        for (int i = 0; i < result_len; i++) {
            printf("(%d, %d, %f)\n", results[i].i, results[i].j, results[i].diff);
        }
        free(results);
    }
}

int main() {
    analyze_data();
    return 0;
}