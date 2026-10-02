#include <stdio.h>

typedef struct {
    int state;
    int energy;
} ThermodynamicSystem;

ThermodynamicSystem* ThermodynamicSystem_new(int state, int energy) {
    ThermodynamicSystem* self = (ThermodynamicSystem*)malloc(sizeof(ThermodynamicSystem));
    self->state = state;
    self->energy = energy;
    return self;
}

void ThermodynamicSystem_update_state(ThermodynamicSystem* self) {
    if (self->energy > 0) {
        self->state += 1;
        self->energy -= 1;
    }
}

typedef struct {
    ThermodynamicSystem* system;
    int max_steps;
    int current_step;
} Simulation;

Simulation* Simulation_new(ThermodynamicSystem* system, int max_steps) {
    Simulation* self = (Simulation*)malloc(sizeof(Simulation));
    self->system = system;
    self->max_steps = max_steps;
    self->current_step = 0;
    return self;
}

int Simulation_step(Simulation* self, int* state, int* energy) {
    if (self->current_step < self->max_steps) {
        ThermodynamicSystem_update_state(self->system);
        *state = self->system->state;
        *energy = self->system->energy;
        self->current_step += 1;
        return 0;
    }
    *state = self->system->state;
    *energy = self->system->energy;
    return 1;
}

void main() {
    int initial_state = 0;
    int initial_energy = 10;
    int max_steps = 15;
    ThermodynamicSystem* system = ThermodynamicSystem_new(initial_state, initial_energy);
    Simulation* simulation = Simulation_new(system, max_steps);
    int state, energy;
    int done = 0;
    while (1) {
        done = Simulation_step(simulation, &state, &energy);
        printf("Step: %d, State: %d, Energy: %d\n", simulation->current_step, state, energy);
        if (done) {
            break;
        }
    }
    free(system);
    free(simulation);
}