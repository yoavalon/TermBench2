#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *a;
    double *b;
    double *x;
    double *y;
    int len_a;
    int len_b;
} DigitalFilter;

DigitalFilter* DigitalFilter_init(double *a, double *b) {
    DigitalFilter *filter = (DigitalFilter*)malloc(sizeof(DigitalFilter));
    filter->len_a = 2;
    filter->len_b = 2;
    filter->a = a;
    filter->b = b;
    filter->x = (double*)calloc(filter->len_a - 1, sizeof(double));
    filter->y = (double*)calloc(filter->len_b - 1, sizeof(double));
    return filter;
}

double DigitalFilter_process(DigitalFilter *filter, double sample) {
    for (int i = 1; i < filter->len_a - 1; i++) {
        filter->x[i-1] = filter->x[i];
    }
    filter->x[filter->len_a - 2] = sample;
    double output = filter->b[0] * filter->x[0] + filter->b[1] * filter->x[1];
    for (int i = 1; i < filter->len_a - 1; i++) {
        output -= filter->a[i] * filter->y[i-1];
    }
    for (int i = 1; i < filter->len_b - 1; i++) {
        filter->y[i-1] = filter->y[i];
    }
    filter->y[filter->len_b - 2] = output;
    return output;
}

typedef struct {
    double frequency;
    double sample_rate;
    double duration;
} SignalGenerator;

double* SignalGenerator_generate(SignalGenerator *generator) {
    int length = (int)(generator->sample_rate * generator->duration);
    double *signal = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double t = i / generator->sample_rate;
        signal[i] = sin(2 * M_PI * generator->frequency * t);
    }
    return signal;
}

double* filter_signal(double *signal, int length, double *a, double *b, int sample_rate, double duration) {
    DigitalFilter *filter = DigitalFilter_init(a, b);
    double *filtered_signal = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        filtered_signal[i] = DigitalFilter_process(filter, signal[i]);
    }
    free(filter->x);
    free(filter->y);
    free(filter);
    return filtered_signal;
}

void main() {
    double coefficients_a[] = {1, -0.9};
    double coefficients_b[] = {0.5, 0.5};
    SignalGenerator generator = {5, 1000, 1};
    double *signal = SignalGenerator_generate(&generator);
    double *filtered_signal = filter_signal(signal, 1000, coefficients_a, coefficients_b, 1000, 1);
    for (int i = 0; i < 1000; i++) {
        printf("%f\n", filtered_signal[i]);
    }
    free(signal);
    free(filtered_signal);
}