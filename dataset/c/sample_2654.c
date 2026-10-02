#include <stdio.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    int n;
    double sequence[100];
} SequenceSimulator;

void SequenceSimulator_init(SequenceSimulator *self, double a, double b, int n) {
    self->a = a;
    self->b = b;
    self->n = n;
}

void SequenceSimulator_generate_sequence(SequenceSimulator *self) {
    for (int i = 0; i < self->n; i++) {
        double value = self->a + i * self->b;
        self->sequence[i] = value;
    }
}

double* SequenceSimulator_calculate_thermodynamic_states(SequenceSimulator *self) {
    static double states[100];
    for (int i = 0; i < self->n; i++) {
        double value = self->sequence[i];
        double state = exp(-value);
        states[i] = state;
    }
    return states;
}

typedef struct {
    double data[100];
} DataAnalyzer;

void DataAnalyzer_init(DataAnalyzer *self, double *data) {
    for (int i = 0; i < 100; i++) {
        self->data[i] = data[i];
    }
}

double DataAnalyzer_average(DataAnalyzer *self) {
    double sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += self->data[i];
    }
    return sum / 100;
}

double DataAnalyzer_max_value(DataAnalyzer *self) {
    double max = self->data[0];
    for (int i = 1; i < 100; i++) {
        if (self->data[i] > max) {
            max = self->data[i];
        }
    }
    return max;
}

double DataAnalyzer_min_value(DataAnalyzer *self) {
    double min = self->data[0];
    for (int i = 1; i < 100; i++) {
        if (self->data[i] < min) {
            min = self->data[i];
        }
    }
    return min;
}

int main() {
    double a = 0;
    double b = 0.1;
    int n = 100;
    SequenceSimulator simulator;
    SequenceSimulator_init(&simulator, a, b, n);
    SequenceSimulator_generate_sequence(&simulator);
    double *states = SequenceSimulator_calculate_thermodynamic_states(&simulator);
    DataAnalyzer analyzer;
    DataAnalyzer_init(&analyzer, states);
    printf("Average State: %f\n", DataAnalyzer_average(&analyzer));
    printf("Max State: %f\n", DataAnalyzer_max_value(&analyzer));
    printf("Min State: %f\n", DataAnalyzer_min_value(&analyzer));
    return 0;
}