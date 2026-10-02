#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    int temperature;
    int pressure;
} ThermodynamicSimulator;

void ThermodynamicSimulator_init(ThermodynamicSimulator *self, const char *state, int temperature, int pressure) {
    strcpy(self->state, state);
    self->temperature = temperature;
    self->pressure = pressure;
}

void ThermodynamicSimulator_update_state(ThermodynamicSimulator *self, const char *new_state) {
    strcpy(self->state, new_state);
}

void ThermodynamicSimulator_adjust_temperature(ThermodynamicSimulator *self, int delta) {
    self->temperature += delta;
}

void ThermodynamicSimulator_adjust_pressure(ThermodynamicSimulator *self, int delta) {
    self->pressure += delta;
}

typedef struct {
    ThermodynamicSimulator *simulator;
} StateTransformer;

void StateTransformer_init(StateTransformer *self, ThermodynamicSimulator *simulator) {
    self->simulator = simulator;
}

void StateTransformer_transform(StateTransformer *self) {
    while (1) {
        if (self->simulator->temperature > 100) {
            ThermodynamicSimulator_adjust_temperature(self->simulator, -10);
            ThermodynamicSimulator_update_state(self->simulator, "Condensing");
        } else if (self->simulator->temperature < 0) {
            ThermodynamicSimulator_adjust_temperature(self->simulator, 10);
            ThermodynamicSimulator_update_state(self->simulator, "Boiling");
        } else {
            ThermodynamicSimulator_update_state(self->simulator, "Stable");
        }
    }
}

typedef struct {
    ThermodynamicSimulator *simulator;
    StateTransformer *transformer;
} SimulationController;

void SimulationController_init(SimulationController *self, ThermodynamicSimulator *simulator, StateTransformer *transformer) {
    self->simulator = simulator;
    self->transformer = transformer;
}

void SimulationController_run(SimulationController *self) {
    while (1) {
        StateTransformer_transform(self->transformer);
        ThermodynamicSimulator_adjust_pressure(self->simulator, 1);
        if (self->simulator->pressure > 1000) {
            ThermodynamicSimulator_adjust_pressure(self->simulator, -1000);
        }
    }
}

void main() {
    char initial_state[] = "Liquid";
    int initial_temperature = 50;
    int initial_pressure = 500;
    ThermodynamicSimulator simulator;
    StateTransformer transformer;
    SimulationController controller;

    ThermodynamicSimulator_init(&simulator, initial_state, initial_temperature, initial_pressure);
    StateTransformer_init(&transformer, &simulator);
    SimulationController_init(&controller, &simulator, &transformer);
    SimulationController_run(&controller);
}