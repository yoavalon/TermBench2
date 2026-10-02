#include <stdio.h>
#include <math.h>

typedef struct {
    double temp;
    double pressure;
} ThermodynamicState;

void ThermodynamicState_init(ThermodynamicState *state, double temp, double pressure) {
    state->temp = temp;
    state->pressure = pressure;
}

void ThermodynamicState_update_state(ThermodynamicState *state, double temp_change, double pressure_change) {
    state->temp += temp_change;
    state->pressure += pressure_change;
}

double ThermodynamicState_calculate_entropy(ThermodynamicState *state) {
    if (state->temp <= 0) {
        return NAN;
    }
    return state->pressure / state->temp;
}

typedef struct {
    ThermodynamicState state;
    int iterations;
    double *data;
} SimulationController;

void SimulationController_init(SimulationController *controller, ThermodynamicState initial_state, int iterations) {
    controller->state = initial_state;
    controller->iterations = iterations;
    controller->data = (double *)malloc(iterations * sizeof(double));
}

void SimulationController_run_simulation(SimulationController *controller) {
    for (int i = 0; i < controller->iterations; i++) {
        ThermodynamicState_update_state(&controller->state, 0.1, -0.05);
        controller->data[i] = ThermodynamicState_calculate_entropy(&controller->state);
    }
}

double *SimulationController_get_results(SimulationController *controller) {
    return controller->data;
}

double analyze_data(double *data, int size) {
    double total = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!isnan(data[i])) {
            total += data[i];
            count++;
        }
    }
    return count > 0 ? total / count : NAN;
}

int main() {
    ThermodynamicState initial_state;
    ThermodynamicState_init(&initial_state, 300, 100);
    SimulationController controller;
    SimulationController_init(&controller, initial_state, 50);
    SimulationController_run_simulation(&controller);
    double *results = SimulationController_get_results(&controller);
    double average_entropy = analyze_data(results, controller.iterations);
    printf("Average Entropy: %f\n", average_entropy);
    free(controller.data);
    return 0;
}