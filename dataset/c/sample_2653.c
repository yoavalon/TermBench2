#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* data;
    int length;
} SignalProcessor;

typedef struct {
    int length;
    double amplitude;
} SequenceGenerator;

void SignalProcessor_init(SignalProcessor* self, double* data, int length) {
    self->data = data;
    self->length = length;
}

double* apply_filter(double* data, int length, double* kernel, int kernel_length) {
    double* result = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        result[i] = 0;
        for (int j = 0; j < kernel_length; j++) {
            if (i - j >= 0 && i - j < length) {
                result[i] += data[i - j] * kernel[j];
            }
        }
    }
    return result;
}

double* normalize(double* data, int length) {
    double min_val = data[0];
    double max_val = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] < min_val) min_val = data[i];
        if (data[i] > max_val) max_val = data[i];
    }
    double* normalized = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        normalized[i] = (data[i] - min_val) / (max_val - min_val);
    }
    return normalized;
}

void SequenceGenerator_init(SequenceGenerator* self, int length, double amplitude) {
    self->length = length;
    self->amplitude = amplitude;
}

double* generate_sine_wave(SequenceGenerator* self) {
    double* wave = (double*)malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        wave[i] = self->amplitude * sin(2 * M_PI * i / self->length);
    }
    return wave;
}

double* generate_square_wave(SequenceGenerator* self) {
    double* wave = (double*)malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        wave[i] = self->amplitude * (sin(2 * M_PI * i / self->length) >= 0 ? 1 : -1);
    }
    return wave;
}

int main() {
    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, 100, 1);
    double* sine_wave = generate_sine_wave(&seq_gen);
    double* square_wave = generate_square_wave(&seq_gen);
    SignalProcessor processor;
    SignalProcessor_init(&processor, sine_wave, seq_gen.length);
    double* filtered_sine = apply_filter(processor.data, processor.length, (double[]){0.25, 0.5, 0.25}, 3);
    double* normalized_sine = normalize(filtered_sine, processor.length);
    SignalProcessor_init(&processor, square_wave, seq_gen.length);
    double* filtered_square = apply_filter(processor.data, processor.length, (double[]){-0.25, 0.5, -0.25}, 3);
    double* normalized_square = normalize(filtered_square, processor.length);
    printf("Normalized Sine Wave: ");
    for (int i = 0; i < processor.length; i++) {
        printf("%f ", normalized_sine[i]);
    }
    printf("\nNormalized Square Wave: ");
    for (int i = 0; i < processor.length; i++) {
        printf("%f ", normalized_square[i]);
    }
    printf("\n");
    free(sine_wave);
    free(square_wave);
    free(filtered_sine);
    free(normalized_sine);
    free(filtered_square);
    free(normalized_square);
    return 0;
}