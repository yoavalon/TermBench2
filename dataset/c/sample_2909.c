#include <stdio.h>

typedef struct {
    int base;
    int increment;
    int current;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int base, int increment) {
    self->base = base;
    self->increment = increment;
    self->current = base;
}

int SequenceGenerator_next_value(SequenceGenerator *self) {
    self->current += self->increment;
    return self->current;
}

typedef struct {
    double initial_reward;
    double decay_rate;
    double current_reward;
} RewardCalculator;

void RewardCalculator_init(RewardCalculator *self, double initial_reward, double decay_rate) {
    self->initial_reward = initial_reward;
    self->decay_rate = decay_rate;
    self->current_reward = initial_reward;
}

double RewardCalculator_calculate(RewardCalculator *self) {
    self->current_reward *= self->decay_rate;
    return self->current_reward;
}

typedef struct {
    SequenceGenerator sequence;
    RewardCalculator reward;
} Environment;

void Environment_init(Environment *self, SequenceGenerator *sequence_generator, RewardCalculator *reward_calculator) {
    self->sequence = *sequence_generator;
    self->reward = *reward_calculator;
}

void Environment_step(Environment *self, int *value, double *reward) {
    *value = SequenceGenerator_next_value(&self->sequence);
    *reward = RewardCalculator_calculate(&self->reward);
}

int main() {
    int base = 1;
    int increment = 1;
    double initial_reward = 100;
    double decay_rate = 0.99;
    SequenceGenerator sequence_generator;
    RewardCalculator reward_calculator;
    Environment environment;
    int value;
    double reward;

    SequenceGenerator_init(&sequence_generator, base, increment);
    RewardCalculator_init(&reward_calculator, initial_reward, decay_rate);
    Environment_init(&environment, &sequence_generator, &reward_calculator);

    while (1) {
        Environment_step(&environment, &value, &reward);
        printf("Value: %d, Reward: %f\n", value, reward);
    }

    return 0;
}