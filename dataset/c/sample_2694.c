#include <stdio.h>
#include <math.h>

typedef struct {
    int start;
    int end;
    int step;
    int current;
} SequenceGenerator;

typedef struct {
    double initial_reward;
    double decay_rate;
    double current_reward;
} RewardCalculator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int end, int step) {
    self->start = start;
    self->end = end;
    self->step = step;
    self->current = start;
}

int SequenceGenerator_generate(SequenceGenerator *self, int *value) {
    if (self->current < self->end) {
        *value = self->current;
        self->current += self->step;
        return 1;
    }
    return 0;
}

void RewardCalculator_init(RewardCalculator *self, double initial_reward, double decay_rate) {
    self->initial_reward = initial_reward;
    self->decay_rate = decay_rate;
    self->current_reward = initial_reward;
}

double RewardCalculator_calculate(RewardCalculator *self, int step) {
    self->current_reward = self->initial_reward * pow(self->decay_rate, step);
    return self->current_reward;
}

double simulate(SequenceGenerator *sequence_generator, RewardCalculator *reward_calculator, int max_steps) {
    int steps = 0;
    double total_reward = 0;
    int value;
    while (SequenceGenerator_generate(sequence_generator, &value)) {
        if (steps >= max_steps) {
            break;
        }
        double reward = RewardCalculator_calculate(reward_calculator, steps);
        total_reward += reward;
        steps += 1;
    }
    return total_reward;
}

void main() {
    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, 0, 10, 1);
    RewardCalculator reward_calc;
    RewardCalculator_init(&reward_calc, 1.0, 0.9);
    int max_steps = 5;
    double result = simulate(&seq_gen, &reward_calc, max_steps);
    printf("%f\n", result);
}