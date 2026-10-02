c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *sequence;
    int sequence_size;
    int current_value;
} SequenceGenerator;

typedef struct {
    double discount_factor;
} RewardCalculator;

typedef struct {
    SequenceGenerator *generator;
    RewardCalculator *calculator;
} SimulationController;

void SequenceGenerator_init(SequenceGenerator *self) {
    self->sequence = NULL;
    self->sequence_size = 0;
    self->current_value = 0;
}

int SequenceGenerator_generate_next(SequenceGenerator *self) {
    self->current_value += rand() % 10 + 1;
    self->sequence = realloc(self->sequence, (self->sequence_size + 1) * sizeof(int));
    self->sequence[self->sequence_size++] = self->current_value;
    return self->current_value;
}

void RewardCalculator_init(RewardCalculator *self, double discount_factor) {
    self->discount_factor = discount_factor;
}

double RewardCalculator_calculate_reward(RewardCalculator *self, SequenceGenerator *generator) {
    double reward = 0;
    for (int i = 0; i < generator->sequence_size; i++) {
        reward += generator->sequence[i] * pow(self->discount_factor, i);
    }
    return reward;
}

void SimulationController_init(SimulationController *self, SequenceGenerator *generator, RewardCalculator *calculator) {
    self->generator = generator;
    self->calculator = calculator;
}

void SimulationController_run_simulation(SimulationController *self) {
    while (1) {
        int next_value = SequenceGenerator_generate_next(self->generator);
        double reward = RewardCalculator_calculate_reward(self->calculator, self->generator);
        printf("Next Value: %d, Total Reward: %.2f\n", next_value, reward);
    }
}

int main() {
    srand(time(NULL));
    SequenceGenerator generator;
    SequenceGenerator_init(&generator);
    RewardCalculator calculator;
    RewardCalculator_init(&calculator, 0.9);
    SimulationController controller;
    SimulationController_init(&controller, &generator, &calculator);
    SimulationController_run_simulation(&controller);
    return 0;
}