#include <stdio.h>
#include <math.h>
#include <string.h>

typedef double Vector[3];

void process_data(char* data[], int data_size, Vector* vectors) {
    for (int i = 0; i < data_size; i++) {
        int length = strlen(data[i]);
        int sum = 0;
        for (int j = 0; j < length; j++) {
            sum += (int)data[i][j];
        }
        vectors[i][0] = length;
        vectors[i][1] = sqrt(length);
        vectors[i][2] = (double)sum / length;
    }
}

void analyze_sequences(char* sequences[][], int seq_size, Vector* results) {
    for (int i = 0; i < seq_size; i++) {
        Vector processed[2];
        process_data(sequences[i], 2, processed);
        Vector average_vector = {0};
        for (int j = 0; j < 3; j++) {
            average_vector[j] = (processed[0][j] + processed[1][j]) / 2;
        }
        results[i] = average_vector;
    }
}

int main() {
    char* sequences[3][2] = {{"hello", "world"}, {"data", "science"}, {"python", "programming"}};
    Vector analysis[3];
    analyze_sequences(sequences, 3, analysis);
    for (int i = 0; i < 3; i++) {
        printf("[%.1f, %.1f, %.1f]\n", analysis[i][0], analysis[i][1], analysis[i][2]);
    }
    return 0;
}