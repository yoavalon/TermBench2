#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double* conditions;
    double* boundaries;
    int iteration;
} StateSimulator;

typedef struct {
    double limit1;
    double limit2;
} BoundaryConditions;

void StateSimulator_init(StateSimulator* self, double* initial_conditions, double* boundary_conditions) {
    self->conditions = initial_conditions;
    self->boundaries = boundary_conditions;
    self->iteration = 0;
}

void StateSimulator_update_conditions(StateSimulator* self, int size) {
    for (int i = 0; i < size; i++) {
        self->conditions[i] += ((double)rand() / RAND_MAX) * 0.1;
        self->conditions[i] = (self->conditions[i] < self->boundaries[0]) ? self->boundaries[0] :
                             (self->conditions[i] > self->boundaries[1]) ? self->boundaries[1] :
                             self->conditions[i];
    }
}

int StateSimulator_check_stability(StateSimulator* self, int size) {
    for (int i = 0; i < size; i++) {
        if (fabs(self->conditions[i] - self->boundaries[0]) > 0.01 && fabs(self->conditions[i] - self->boundaries[1]) > 0.01) {
            return 0;
        }
    }
    return 1;
}

void BoundaryConditions_init(BoundaryConditions* self, double lower, double upper) {
    self->limit1 = lower;
    self->limit2 = upper;
}

double* BoundaryConditions_get_boundaries(BoundaryConditions* self) {
    static double boundaries[2];
    boundaries[0] = self->limit1;
    boundaries[1] = self->limit2;
    return boundaries;
}

double* simulate_state(double* initial_conditions, double* boundaries, int max_iterations, int size) {
    StateSimulator simulator;
    StateSimulator_init(&simulator, initial_conditions, boundaries);
    for (int i = 0; i < max_iterations; i++) {
        StateSimulator_update_conditions(&simulator, size);
        if (StateSimulator_check_stability(&simulator, size)) {
            break;
        }
    }
    return simulator.conditions;
}

int main() {
    srand(time(NULL));
    double initial_conditions[] = {0.5, 0.5, 0.5};
    BoundaryConditions boundary_conditions;
    BoundaryConditions_init(&boundary_conditions, 0, 1);
    double* boundaries = BoundaryConditions_get_boundaries(&boundary_conditions);
    int max_iterations = 100;
    int size = sizeof(initial_conditions) / sizeof(initial_conditions[0]);
    double* final_state = simulate_state(initial_conditions, boundaries, max_iterations, size);
    for (int i = 0; i < size; i++) {
        printf("%f ", final_state[i]);
    }
    printf("\n");
    return 0;
}