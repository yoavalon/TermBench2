#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_SIZE 1024
#define FILTER_SIZE 3

void main() {
    double signal[SIGNAL_SIZE];
    double filter_coeff[FILTER_SIZE] = {0.25, 0.5, 0.25};
    for (int i = 0; i < SIGNAL_SIZE; i++) {
        signal[i] = (double)rand() / RAND_MAX;
    }
    while (1) {
        double temp[SIGNAL_SIZE];
        for (int i = 0; i < SIGNAL_SIZE; i++) {
            temp[i] = 0;
            for (int j = 0; j < FILTER_SIZE; j++) {
                if (i + j < SIGNAL_SIZE) {
                    temp[i] += signal[i + j] * filter_coeff[j];
                }
            }
        }
        for (int i = 0; i < SIGNAL_SIZE; i++) {
            signal[i] = temp[i];
        }
    }
}