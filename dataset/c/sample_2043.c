#include <stdio.h>

typedef struct {
    float temp;
    float pressure;
} SimulationState;

void SimulationState_init(SimulationState *self, float temp, float pressure) {
    self->temp = temp;
    self->pressure = pressure;
}

void SimulationState_update_temperature(SimulationState *self, float delta) {
    self->temp += delta;
}

void SimulationState_update_pressure(SimulationState *self, float delta) {
    self->pressure += delta;
}

float SimulationState_calculate_energy(SimulationState *self) {
    return self->temp * self->pressure;
}

typedef struct {
    SimulationState *states;
    int size;
} EnergyAnalyzer;

void EnergyAnalyzer_init(EnergyAnalyzer *self, SimulationState *states, int size) {
    self->states = states;
    self->size = size;
}

float EnergyAnalyzer_analyze(EnergyAnalyzer *self) {
    float total_energy = 0.0;
    for (int i = 0; i < self->size; i++) {
        total_energy += SimulationState_calculate_energy(&self->states[i]);
    }
    return total_energy;
}

void simulate_and_analyze(float *initial_energy, float *final_energy) {
    SimulationState states[10];
    for (int i = 0; i < 10; i++) {
        SimulationState_init(&states[i], (float)(i + 1), (float)(20 - i));
    }
    EnergyAnalyzer analyzer;
    EnergyAnalyzer_init(&analyzer, states, 10);
    *initial_energy = EnergyAnalyzer_analyze(&analyzer);
    for (int i = 0; i < 10; i++) {
        SimulationState_update_temperature(&states[i], 0.5);
        SimulationState_update_pressure(&states[i], -0.5);
    }
    *final_energy = EnergyAnalyzer_analyze(&analyzer);
}

int main() {
    float initial_energy, final_energy;
    simulate_and_analyze(&initial_energy, &final_energy);
    printf("Initial Energy: %f\n", initial_energy);
    printf("Final Energy: %f\n", final_energy);
    return 0;
}