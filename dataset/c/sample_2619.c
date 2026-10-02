#include <stdio.h>

typedef struct {
    int current;
    int stop;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int stop, int step) {
    self->current = start;
    self->stop = stop;
    self->step = step;
}

int SequenceGenerator_generate(SequenceGenerator *self) {
    if (self->current < self->stop) {
        int value = self->current;
        self->current += self->step;
        return value;
    }
    return -1; // Signal end of sequence
}

typedef struct {
    SequenceGenerator sequence;
    double temperature;
} ThermodynamicSimulator;

void ThermodynamicSimulator_init(ThermodynamicSimulator *self, SequenceGenerator *sequence) {
    self->sequence = *sequence;
    self->temperature = 300.0;
}

double ThermodynamicSimulator_simulate(ThermodynamicSimulator *self) {
    int value = SequenceGenerator_generate(&self->sequence);
    if (value != -1) {
        self->temperature += value * 0.1;
        return self->temperature;
    }
    return -1; // Signal end of simulation
}

typedef struct {
    ThermodynamicSimulator simulator;
    double data[100];
    int data_count;
} DataCollector;

void DataCollector_init(DataCollector *self, ThermodynamicSimulator *simulator) {
    self->simulator = *simulator;
    self->data_count = 0;
}

void DataCollector_collect(DataCollector *self) {
    double temp;
    while ((temp = ThermodynamicSimulator_simulate(&self->simulator)) != -1) {
        self->data[self->data_count++] = temp;
    }
}

void main() {
    int start = 0, stop = 100, step = 5;
    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, start, stop, step);
    ThermodynamicSimulator simulator;
    ThermodynamicSimulator_init(&simulator, &sequence);
    DataCollector collector;
    DataCollector_init(&collector, &simulator);
    DataCollector_collect(&collector);
    for (int i = 0; i < collector.data_count; i++) {
        printf("%f ", collector.data[i]);
    }
    printf("\n");
}