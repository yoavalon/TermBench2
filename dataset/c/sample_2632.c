#include <stdio.h>

typedef struct {
    int current;
    int end;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int end, int step) {
    self->current = start;
    self->end = end;
    self->step = step;
}

int SequenceGenerator_has_next(SequenceGenerator *self) {
    return self->current < self->end;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    if (SequenceGenerator_has_next(self)) {
        int value = self->current;
        self->current += self->step;
        return value;
    }
    return -1;
}

typedef struct {
    SequenceGenerator sequence;
    int states[100][3];
    int state_count;
} StateSimulator;

void StateSimulator_init(StateSimulator *self, SequenceGenerator *sequence) {
    self->sequence = *sequence;
    self->state_count = 0;
}

void StateSimulator_simulate(StateSimulator *self) {
    while (SequenceGenerator_has_next(&self->sequence)) {
        int temp = SequenceGenerator_next(&self->sequence);
        int pressure = temp * 1.5;
        int volume = temp * 2;
        self->states[self->state_count][0] = temp;
        self->states[self->state_count][1] = pressure;
        self->states[self->state_count][2] = volume;
        self->state_count++;
    }
}

typedef struct {
    StateSimulator simulator;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, StateSimulator *simulator) {
    self->simulator = *simulator;
}

void DataProcessor_process(DataProcessor *self) {
    for (int i = 0; i < self->simulator.state_count; i++) {
        printf("Temperature: %d, Pressure: %d, Volume: %d\n",
               self->simulator.states[i][0],
               self->simulator.states[i][1],
               self->simulator.states[i][2]);
    }
}

void main() {
    SequenceGenerator seq;
    SequenceGenerator_init(&seq, 100, 300, 50);
    StateSimulator sim;
    StateSimulator_init(&sim, &seq);
    StateSimulator_simulate(&sim);
    DataProcessor processor;
    DataProcessor_init(&processor, &sim);
    DataProcessor_process(&processor);
}