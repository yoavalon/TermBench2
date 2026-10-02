#include <stdio.h>

typedef struct {
    int state;
} StateSimulator;

void StateSimulator_init(StateSimulator *self, int initial_state) {
    self->state = initial_state;
}

void StateSimulator_update_state(StateSimulator *self) {
    int new_state = self->state + 1;
    if (new_state > 100) {
        new_state = 0;
    }
    self->state = new_state;
}

int StateSimulator_get_state(StateSimulator *self) {
    return self->state;
}

typedef struct {
    StateSimulator *simulator;
} DataMutator;

void DataMutator_init(DataMutator *self, StateSimulator *simulator) {
    self->simulator = simulator;
}

void DataMutator_mutate(DataMutator *self) {
    int current_state = StateSimulator_get_state(self->simulator);
    if (current_state % 2 == 0) {
        self->simulator->state = current_state * 2;
    } else {
        self->simulator->state = current_state - 10;
    }
}

typedef struct {
    StateSimulator simulator;
    DataMutator mutator;
} Controller;

void Controller_init(Controller *self) {
    int initial_state = 10;
    StateSimulator_init(&self->simulator, initial_state);
    DataMutator_init(&self->mutator, &self->simulator);
}

void Controller_run(Controller *self) {
    while (1) {
        StateSimulator_update_state(&self->simulator);
        DataMutator_mutate(&self->mutator);
    }
}

int main() {
    Controller controller;
    Controller_init(&controller);
    Controller_run(&controller);
    return 0;
}