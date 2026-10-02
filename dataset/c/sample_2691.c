#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int n;
} SequenceSimulator;

void SequenceSimulator_init(SequenceSimulator *sim, int a, int b, int n) {
    sim->a = a;
    sim->b = b;
    sim->n = n;
}

int* SequenceSimulator_generate_sequence(SequenceSimulator *sim) {
    int *sequence = (int*)malloc(sim->n * sizeof(int));
    int current = sim->a;
    for (int i = 0; i < sim->n; i++) {
        sequence[i] = current;
        current = sim->b * current;
    }
    return sequence;
}

typedef struct {
    int sum;
    int max;
    int min;
    double mean;
} Analysis;

Analysis SequenceSimulator_analyze_sequence(SequenceSimulator *sim, int *sequence) {
    Analysis analysis;
    analysis.sum = 0;
    analysis.max = sequence[0];
    analysis.min = sequence[0];
    for (int i = 0; i < sim->n; i++) {
        analysis.sum += sequence[i];
        if (sequence[i] > analysis.max) analysis.max = sequence[i];
        if (sequence[i] < analysis.min) analysis.min = sequence[i];
    }
    analysis.mean = (double)analysis.sum / sim->n;
    return analysis;
}

typedef struct {
    int temperature;
    int pressure;
} ThermodynamicState;

void ThermodynamicState_init(ThermodynamicState *state, int temperature, int pressure) {
    state->temperature = temperature;
    state->pressure = pressure;
}

void ThermodynamicState_update_state(ThermodynamicState *state, Analysis analysis) {
    state->temperature = analysis.max;
    state->pressure = analysis.min;
}

int main() {
    SequenceSimulator sim;
    SequenceSimulator_init(&sim, 2, 3, 10);
    int *seq = SequenceSimulator_generate_sequence(&sim);
    Analysis analysis = SequenceSimulator_analyze_sequence(&sim, seq);
    ThermodynamicState state;
    ThermodynamicState_init(&state, 300, 1);
    ThermodynamicState_update_state(&state, analysis);
    printf("Final Temperature: %d, Final Pressure: %d\n", state.temperature, state.pressure);
    free(seq);
    return 0;
}