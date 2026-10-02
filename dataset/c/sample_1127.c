#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
    int energy;
    int temperature;
} ThermodynamicSimulation;

void update_state(ThermodynamicSimulation *simulator) {
    if (simulator->temperature > 300) {
        strcpy(simulator->state, "high");
    } else if (simulator->temperature < 100) {
        strcpy(simulator->state, "low");
    } else {
        strcpy(simulator->state, "stable");
    }
}

void adjust_energy(ThermodynamicSimulation *simulator) {
    if (strcmp(simulator->state, "high") == 0) {
        simulator->energy -= 10;
    } else if (strcmp(simulator->state, "low") == 0) {
        simulator->energy += 10;
    }
}

void simulate(ThermodynamicSimulation *simulator) {
    update_state(simulator);
    adjust_energy(simulator);
    simulator->temperature = simulator->energy / 10;
}

void recursive_simulation(ThermodynamicSimulation *simulator) {
    simulate(simulator);
    recursive_simulation(simulator);
}

int main() {
    ThermodynamicSimulation simulator;
    strcpy(simulator.state, "unknown");
    simulator.energy = 250;
    simulator.temperature = 220;
    recursive_simulation(&simulator);
    return 0;
}