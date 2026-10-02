#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    int temperature;
    int pressure;
} SimulationEnvironment;

void SimulationEnvironment_init(SimulationEnvironment *self, const char *initial_state, int temperature, int pressure) {
    strcpy(self->state, initial_state);
    self->temperature = temperature;
    self->pressure = pressure;
}

void SimulationEnvironment_update_state(SimulationEnvironment *self, const char *new_state) {
    strcpy(self->state, new_state);
}

void SimulationEnvironment_adjust_temperature(SimulationEnvironment *self, int delta) {
    self->temperature += delta;
}

void SimulationEnvironment_adjust_pressure(SimulationEnvironment *self, int delta) {
    self->pressure += delta;
}

typedef struct {
    // No fields needed for this struct
} StateAnalyzer;

const char* StateAnalyzer_analyze_state(StateAnalyzer *self, const char *state, int temperature, int pressure) {
    if (temperature > 100) {
        return "High temperature";
    } else if (pressure > 100) {
        return "High pressure";
    } else {
        return "Stable state";
    }
}

typedef struct {
    SimulationEnvironment *environment;
    StateAnalyzer *analyzer;
} SimulationController;

void SimulationController_init(SimulationController *self, SimulationEnvironment *environment, StateAnalyzer *analyzer) {
    self->environment = environment;
    self->analyzer = analyzer;
}

void SimulationController_run_simulation(SimulationController *self) {
    while (1) {
        const char* analysis = StateAnalyzer_analyze_state(self->analyzer, self->environment->state, self->environment->temperature, self->environment->pressure);
        if (strcmp(analysis, "High temperature") == 0) {
            SimulationEnvironment_adjust_temperature(self->environment, -10);
        } else if (strcmp(analysis, "High pressure") == 0) {
            SimulationEnvironment_adjust_pressure(self->environment, -10);
        }
        SimulationEnvironment_update_state(self->environment, "New State");
    }
}

void main() {
    SimulationEnvironment env;
    SimulationEnvironment_init(&env, "Initial State", 150, 110);
    StateAnalyzer analyzer;
    SimulationController controller;
    SimulationController_init(&controller, &env, &analyzer);
    SimulationController_run_simulation(&controller);
}