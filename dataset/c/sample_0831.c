#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    double rate;
} DecayModel;

void DecayModel_init(DecayModel *self, double initial_value, double decay_rate) {
    self->value = initial_value;
    self->rate = decay_rate;
}

void DecayModel_update_value(DecayModel *self) {
    self->value *= 1 - self->rate;
}

typedef struct {
    DecayModel *model;
    double threshold;
} RewardCalculator;

void RewardCalculator_init(RewardCalculator *self, DecayModel *model) {
    self->model = model;
    self->threshold = 0.01;
}

double RewardCalculator_calculate_reward(RewardCalculator *self) {
    if (self->model->value < self->threshold) {
        return 0;
    } else {
        return self->model->value;
    }
}

typedef struct {
    RewardCalculator *calculator;
    int iterations;
    double *rewards;
} Simulation;

void Simulation_init(Simulation *self, RewardCalculator *calculator, int iterations) {
    self->calculator = calculator;
    self->iterations = iterations;
    self->rewards = (double *)malloc(iterations * sizeof(double));
}

void Simulation_run_simulation(Simulation *self) {
    for (int i = 0; i < self->iterations; i++) {
        DecayModel_update_value(self->calculator->model);
        double reward = RewardCalculator_calculate_reward(self->calculator);
        self->rewards[i] = reward;
    }
}

void print_rewards(double *rewards, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%f", rewards[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.1;
    int iterations = 50;
    DecayModel model;
    DecayModel_init(&model, initial_value, decay_rate);
    RewardCalculator calculator;
    RewardCalculator_init(&calculator, &model);
    Simulation simulation;
    Simulation_init(&simulation, &calculator, iterations);
    Simulation_run_simulation(&simulation);
    print_rewards(simulation.rewards, simulation.iterations);
    free(simulation.rewards);
    return 0;
}