#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 1024

typedef struct {
    double *data;
    int size;
} SignalProcessor;

typedef struct {
    int length;
} SequenceGenerator;

typedef struct {
    double *data;
    int size;
} Analysis;

void SignalProcessor_init(SignalProcessor *sp, double *data, int size) {
    sp->data = data;
    sp->size = size;
}

double* SignalProcessor_apply_filter(SignalProcessor *sp, double *kernel, int kernel_size) {
    double *result = (double *)malloc(sp->size * sizeof(double));
    for (int i = 0; i < sp->size; i++) {
        result[i] = 0;
        for (int j = 0; j < kernel_size; j++) {
            if (i - j >= 0 && i - j < sp->size) {
                result[i] += sp->data[i - j] * kernel[j];
            }
        }
    }
    return result;
}

double* SignalProcessor_normalize(SignalProcessor *sp) {
    double min_val = sp->data[0];
    double max_val = sp->data[0];
    for (int i = 1; i < sp->size; i++) {
        if (sp->data[i] < min_val) min_val = sp->data[i];
        if (sp->data[i] > max_val) max_val = sp->data[i];
    }
    double *normalized = (double *)malloc(sp->size * sizeof(double));
    for (int i = 0; i < sp->size; i++) {
        normalized[i] = (sp->data[i] - min_val) / (max_val - min_val);
    }
    return normalized;
}

void SequenceGenerator_init(SequenceGenerator *sg, int length) {
    sg->length = length;
}

double* SequenceGenerator_generate_sine_wave(SequenceGenerator *sg, double frequency, double amplitude, double phase) {
    double *wave = (double *)malloc(sg->length * sizeof(double));
    for (int i = 0; i < sg->length; i++) {
        wave[i] = amplitude * sin(2 * M_PI * frequency * ((double)i / sg->length) + phase);
    }
    return wave;
}

void Analysis_init(Analysis *a, double *data, int size) {
    a->data = data;
    a->size = size;
}

double* Analysis_calculate_fft(Analysis *a) {
    double *fft_result = (double *)malloc(a->size * sizeof(double));
    for (int k = 0; k < a->size; k++) {
        fft_result[k] = 0;
        for (int n = 0; n < a->size; n++) {
            fft_result[k] += a->data[n] * cos(-2 * M_PI * k * n / a->size) + a->data[n] * sin(-2 * M_PI * k * n / a->size);
        }
    }
    return fft_result;
}

double Analysis_find_peak_frequency(Analysis *a, double *fft_result) {
    double max_val = 0;
    int peak_idx = 0;
    for (int i = 0; i < a->size; i++) {
        if (fabs(fft_result[i]) > max_val) {
            max_val = fabs(fft_result[i]);
            peak_idx = i;
        }
    }
    return (double)peak_idx / a->size;
}

int main() {
    SequenceGenerator sg;
    SequenceGenerator_init(&sg, LENGTH);
    double *signal = SequenceGenerator_generate_sine_wave(&sg, 5, 1, 0);

    SignalProcessor sp;
    SignalProcessor_init(&sp, signal, LENGTH);
    double kernel[3] = {0.25, 0.5, 0.25};
    double *filtered_data = SignalProcessor_apply_filter(&sp, kernel, 3);
    double *normalized_data = SignalProcessor_normalize(&sp);

    Analysis a;
    Analysis_init(&a, normalized_data, LENGTH);
    double *fft_result = Analysis_calculate_fft(&a);
    double peak_frequency = Analysis_find_peak_frequency(&a, fft_result);

    printf("Peak Frequency: %f\n", peak_frequency);

    free(signal);
    free(filtered_data);
    free(normalized_data);
    free(fft_result);

    return 0;
}