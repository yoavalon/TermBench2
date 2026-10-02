#include <stdio.h>
#include <math.h>

typedef struct {
    double* data;
    int sample_rate;
    double* filtered_data;
    int filtered_data_size;
} SignalProcessor;

void SignalProcessor_init(SignalProcessor* self, double* data, int sample_rate) {
    self->data = data;
    self->sample_rate = sample_rate;
    self->filtered_data = NULL;
    self->filtered_data_size = 0;
}

void SignalProcessor_apply_filter(SignalProcessor* self) {
    self->filtered_data = (double*)malloc((self->sample_rate - 1) * sizeof(double));
    for (int i = 0; i < self->sample_rate - 1; i++) {
        double avg = (self->data[i] + self->data[i + 1]) / 2.0;
        self->filtered_data[i] = avg;
    }
    self->filtered_data_size = self->sample_rate - 1;
}

void SignalProcessor_normalize(SignalProcessor* self) {
    double max_val = 0.0;
    for (int i = 0; i < self->filtered_data_size; i++) {
        if (self->filtered_data[i] > max_val) {
            max_val = self->filtered_data[i];
        }
    }
    for (int i = 0; i < self->filtered_data_size; i++) {
        self->filtered_data[i] /= max_val;
    }
}

void SignalProcessor_process(SignalProcessor* self) {
    SignalProcessor_apply_filter(self);
    SignalProcessor_normalize(self);
}

typedef struct {
    double* data;
    double* transformed_data;
    int data_size;
    int transformed_data_size;
} FourierTransform;

void FourierTransform_init(FourierTransform* self, double* data, int data_size) {
    self->data = data;
    self->data_size = data_size;
    self->transformed_data = (double*)malloc(data_size * sizeof(double));
    self->transformed_data_size = data_size;
}

void FourierTransform_compute(FourierTransform* self) {
    for (int k = 0; k < self->data_size; k++) {
        double sum_real = 0.0;
        double sum_imag = 0.0;
        for (int n = 0; n < self->data_size; n++) {
            double angle = 2 * M_PI * k * n / self->data_size;
            sum_real += self->data[n] * cos(angle);
            sum_imag -= self->data[n] * sin(angle);
        }
        self->transformed_data[k] = sum_real * sum_real + sum_imag * sum_imag;
    }
}

void FourierTransform_magnitude(FourierTransform* self) {
    for (int i = 0; i < self->transformed_data_size; i++) {
        self->transformed_data[i] = sqrt(self->transformed_data[i]);
    }
}

typedef struct {
    SignalProcessor* processor;
    FourierTransform* transformer;
} SignalAnalysis;

void SignalAnalysis_init(SignalAnalysis* self, SignalProcessor* processor, FourierTransform* transformer) {
    self->processor = processor;
    self->transformer = transformer;
}

void SignalAnalysis_analyze(SignalAnalysis* self) {
    SignalProcessor_process(self->processor);
    FourierTransform_compute(self->transformer);
    FourierTransform_magnitude(self->transformer);
}

int main() {
    double signal_data[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    int sample_rate = 5;
    SignalProcessor processor;
    SignalProcessor_init(&processor, signal_data, sample_rate);
    FourierTransform transformer;
    FourierTransform_init(&transformer, processor.filtered_data, processor.filtered_data_size);
    SignalAnalysis analysis;
    SignalAnalysis_init(&analysis, &processor, &transformer);
    while (1) {
        SignalAnalysis_analyze(&analysis);
    }
    return 0;
}