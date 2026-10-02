#include <stdio.h>

typedef struct {
    int state;
    int rate;
    int threshold;
} ThermodynamicSimulation;

void ThermodynamicSimulation_init(ThermodynamicSimulation *self, int initial_state, int rate, int threshold) {
    self->state = initial_state;
    self->rate = rate;
    self->threshold = threshold;
}

void ThermodynamicSimulation_update_state(ThermodynamicSimulation *self) {
    self->state += self->rate;
    if (self->state > self->threshold) {
        self->state = self->threshold - (self->state - self->threshold);
    }
}

typedef struct {
    int value;
    int increment;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int increment) {
    self->value = start;
    self->increment = increment;
}

int SequenceGenerator_next_value(SequenceGenerator *self) {
    self->value += self->increment;
    return self->value;
}

typedef struct {
    ThermodynamicSimulation *simulation;
    SequenceGenerator *generator;
} Analysis;

void Analysis_init(Analysis *self, ThermodynamicSimulation *sim, SequenceGenerator *gen) {
    self->simulation = sim;
    self->generator = gen;
}

void Analysis_run(Analysis *self) {
    while (1) {
        ThermodynamicSimulation_update_state(self->simulation);
        int val = SequenceGenerator_next_value(self->generator);
        printf("State: %d, Value: %d\n", self->simulation->state, val);
    }
}

int main() {
    ThermodynamicSimulation sim;
    SequenceGenerator gen;
    Analysis analysis;

    ThermodynamicSimulation_init(&sim, 10, 2, 20);
    SequenceGenerator_init(&gen, 0, 1);
    Analysis_init(&analysis, &sim, &gen);
    Analysis_run(&analysis);

    return 0;
}