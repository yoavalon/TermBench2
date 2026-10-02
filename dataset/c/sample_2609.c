#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int length) {
    self->length = length;
}

double* SequenceGenerator_generate(SequenceGenerator *self) {
    double *sequence = (double *)calloc(self->length, sizeof(double));
    for (int i = 1; i < self->length; i++) {
        sequence[i] = sequence[i - 1] + 0.5;
    }
    return sequence;
}

typedef struct {
    double *coefficients;
    int length;
} FilterApplier;

void FilterApplier_init(FilterApplier *self, double *coefficients, int length) {
    self->coefficients = coefficients;
    self->length = length;
}

double* FilterApplier_apply(FilterApplier *self, double *sequence) {
    double *filtered_sequence = (double *)calloc(self->length, sizeof(double));
    for (int i = 0; i < self->length; i++) {
        for (int j = 0; j < self->length; j++) {
            if (i - j >= 0 && i - j < self->length) {
                filtered_sequence[i] += sequence[i - j] * self->coefficients[j];
            }
        }
    }
    return filtered_sequence;
}

typedef struct {
    SequenceGenerator *generator;
    FilterApplier *filter;
} SignalProcessor;

void SignalProcessor_init(SignalProcessor *self, SequenceGenerator *generator, FilterApplier *filter) {
    self->generator = generator;
    self->filter = filter;
}

double* SignalProcessor_process(SignalProcessor *self) {
    double *sequence = SequenceGenerator_generate(self->generator);
    double *filtered_sequence = FilterApplier_apply(self->filter, sequence);
    free(sequence);
    return filtered_sequence;
}

int main() {
    int length = 100;
    double coefficients[] = {0.25, 0.5, 0.25};
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, length);
    FilterApplier filter_applier;
    FilterApplier_init(&filter_applier, coefficients, 3);
    SignalProcessor processor;
    SignalProcessor_init(&processor, &generator, &filter_applier);
    double *result = SignalProcessor_process(&processor);
    for (int i = 0; i < length; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}