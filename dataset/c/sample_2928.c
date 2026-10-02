#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *state;
    double **matrix;
} ThermodynamicSimulator;

typedef struct {
    ThermodynamicSimulator *simulator;
} StateAnalyzer;

typedef struct {
    ThermodynamicSimulator simulator;
    StateAnalyzer analyzer;
} SimulationManager;

void ThermodynamicSimulator_init(ThermodynamicSimulator *self, double *initial_state, double **transition_matrix) {
    self->state = initial_state;
    self->matrix = transition_matrix;
}

void ThermodynamicSimulator_update_state(ThermodynamicSimulator *self) {
    int len = sizeof(self->state) / sizeof(self->state[0]);
    double *next_state = (double *)malloc(len * sizeof(double));
    for (int i = 0; i < len; i++) {
        next_state[i] = 0;
        for (int j = 0; j < len; j++) {
            next_state[i] += self->state[j] * self->matrix[j][i];
        }
    }
    free(self->state);
    self->state = next_state;
}

void ThermodynamicSimulator_simulate(ThermodynamicSimulator *self) {
    while (1) {
        ThermodynamicSimulator_update_state(self);
    }
}

void StateAnalyzer_init(StateAnalyzer *self, ThermodynamicSimulator *simulator) {
    self->simulator = simulator;
}

void StateAnalyzer_analyze(StateAnalyzer *self) {
    while (1) {
        double *current_state = self->simulator->state;
        int len = sizeof(current_state) / sizeof(current_state[0]);
        int stable = 1;
        for (int i = 0; i < len - 1; i++) {
            if (fabs(current_state[i] - current_state[i + 1]) >= 0.0001) {
                stable = 0;
                break;
            }
        }
        if (stable) {
            break;
        }
    }
}

void SimulationManager_init(SimulationManager *self) {
    double initial_state[] = {1, 0, 0, 0};
    double *transition_matrix[4];
    transition_matrix[0] = (double[]){0.7, 0.1, 0.1, 0.1};
    transition_matrix[1] = (double[]){0.2, 0.6, 0.1, 0.1};
    transition_matrix[2] = (double[]){0.1, 0.1, 0.7, 0.1};
    transition_matrix[3] = (double[]){0.1, 0.1, 0.1, 0.7};
    ThermodynamicSimulator_init(&self->simulator, initial_state, transition_matrix);
    StateAnalyzer_init(&self->analyzer, &self->simulator);
}

void SimulationManager_run(SimulationManager *self) {
    ThermodynamicSimulator_simulate(&self->simulator);
    StateAnalyzer_analyze(&self->analyzer);
}

int main() {
    SimulationManager manager;
    SimulationManager_init(&manager);
    SimulationManager_run(&manager);
    return 0;
}