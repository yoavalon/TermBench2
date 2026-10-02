#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100

typedef struct {
    double* data;
    int size;
} SignalProcessor;

typedef struct {
    double* processed_data;
    int size;
} DataAnalyzer;

typedef struct {
    double mean;
    double std_dev;
} ResultFormatter;

void SignalProcessor_init(SignalProcessor* self, double* data, int size) {
    self->data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        self->data[i] = data[i];
    }
    self->size = size;
}

double* SignalProcessor_filter_signal(SignalProcessor* self, double low, double high) {
    double* fft_data = (double*)malloc(self->size * sizeof(double));
    double* frequencies = (double*)malloc(self->size * sizeof(double));
    double* mask = (double*)malloc(self->size * sizeof(double));
    double* filtered_fft_data = (double*)malloc(self->size * sizeof(double));
    double* ifft_data = (double*)malloc(self->size * sizeof(double));

    // FFT computation (simplified)
    for (int k = 0; k < self->size; k++) {
        double real = 0.0, imag = 0.0;
        for (int n = 0; n < self->size; n++) {
            real += self->data[n] * cos(2 * PI * k * n / self->size);
            imag += self->data[n] * sin(2 * PI * k * n / self->size);
        }
        fft_data[k] = sqrt(real * real + imag * imag);
    }

    // Frequency computation
    for (int k = 0; k < self->size; k++) {
        frequencies[k] = k * SAMPLE_RATE / self->size;
    }

    // Mask creation
    for (int k = 0; k < self->size; k++) {
        mask[k] = (frequencies[k] > low) && (frequencies[k] < high) ? 1.0 : 0.0;
    }

    // Filtered FFT data
    for (int k = 0; k < self->size; k++) {
        filtered_fft_data[k] = fft_data[k] * mask[k];
    }

    // IFFT computation (simplified)
    for (int n = 0; n < self->size; n++) {
        double real = 0.0, imag = 0.0;
        for (int k = 0; k < self->size; k++) {
            real += filtered_fft_data[k] * cos(2 * PI * k * n / self->size);
            imag += filtered_fft_data[k] * sin(2 * PI * k * n / self->size);
        }
        ifft_data[n] = real / self->size;
    }

    free(fft_data);
    free(frequencies);
    free(mask);
    free(filtered_fft_data);
    return ifft_data;
}

void DataAnalyzer_init(DataAnalyzer* self, double* processed_data, int size) {
    self->processed_data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        self->processed_data[i] = processed_data[i];
    }
    self->size = size;
}

void DataAnalyzer_calculate_statistics(DataAnalyzer* self, double* mean, double* std_dev) {
    double sum = 0.0, sum_sq = 0.0;
    for (int i = 0; i < self->size; i++) {
        sum += self->processed_data[i];
        sum_sq += self->processed_data[i] * self->processed_data[i];
    }
    *mean = sum / self->size;
    *std_dev = sqrt((sum_sq / self->size) - (*mean * *mean));
}

void ResultFormatter_init(ResultFormatter* self, double mean, double std_dev) {
    self->mean = mean;
    self->std_dev = std_dev;
}

void ResultFormatter_format_output(ResultFormatter* self, char* output) {
    sprintf(output, "Mean: %.6f, Std Dev: %.6f", self->mean, self->std_dev);
}

int main() {
    double* raw_data = (double*)malloc(44100 * sizeof(double));
    for (int i = 0; i < 44100; i++) {
        raw_data[i] = ((double)rand() / RAND_MAX);
    }

    SignalProcessor processor;
    SignalProcessor_init(&processor, raw_data, 44100);
    double* filtered_data = SignalProcessor_filter_signal(&processor, 1000, 5000);

    DataAnalyzer analyzer;
    DataAnalyzer_init(&analyzer, filtered_data, 44100);
    double mean, std_dev;
    DataAnalyzer_calculate_statistics(&analyzer, &mean, &std_dev);

    ResultFormatter formatter;
    ResultFormatter_init(&formatter, mean, std_dev);
    char output[100];
    ResultFormatter_format_output(&formatter, output);
    printf("%s\n", output);

    free(raw_data);
    free(filtered_data);
    free(processor.data);
    free(analyzer.processed_data);

    return 0;
}