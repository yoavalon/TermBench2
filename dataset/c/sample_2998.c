#include <stdio.h>

typedef struct {
    int value;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int initial_value, int step) {
    self->value = initial_value;
    self->step = step;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    self->value += self->step;
    return self->value;
}

typedef struct {
    SequenceGenerator *sequence;
    double temperature;
    double pressure;
} ThermodynamicSimulator;

void ThermodynamicSimulator_init(ThermodynamicSimulator *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->temperature = 0.0;
    self->pressure = 1.0;
}

void ThermodynamicSimulator_update_state(ThermodynamicSimulator *self) {
    self->temperature += SequenceGenerator_next(self->sequence) / 100.0;
    self->pressure += SequenceGenerator_next(self->sequence) / 1000.0;
}

void ThermodynamicSimulator_get_state(ThermodynamicSimulator *self, double *temperature, double *pressure) {
    *temperature = self->temperature;
    *pressure = self->pressure;
}

typedef struct {
    ThermodynamicSimulator *simulator;
    double data[1000][2];
    int count;
} DataCollector;

void DataCollector_init(DataCollector *self, ThermodynamicSimulator *simulator) {
    self->simulator = simulator;
    self->count = 0;
}

void DataCollector_collect(DataCollector *self) {
    double temp, press;
    ThermodynamicSimulator_get_state(self->simulator, &temp, &press);
    self->data[self->count][0] = temp;
    self->data[self->count][1] = press;
    self->count++;
}

void DataCollector_display(DataCollector *self) {
    for (int i = 0; i < self->count; i++) {
        printf("(%.2f, %.3f)\n", self->data[i][0], self->data[i][1]);
    }
}

int main() {
    SequenceGenerator seq;
    SequenceGenerator_init(&seq, 1, 1);

    ThermodynamicSimulator sim;
    ThermodynamicSimulator_init(&sim, &seq);

    DataCollector collector;
    DataCollector_init(&collector, &sim);

    while (1) {
        ThermodynamicSimulator_update_state(&sim);
        DataCollector_collect(&collector);
        DataCollector_display(&collector);
    }

    return 0;
}