#include <stdio.h>

typedef struct {
    int start;
    int end;
    int step;
    int current;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int end, int step) {
    self->start = start;
    self->end = end;
    self->step = step;
    self->current = start;
}

int SequenceGenerator_generate(SequenceGenerator *self) {
    if (self->current < self->end) {
        int value = self->current;
        self->current += self->step;
        return value;
    }
    return -1; // Using -1 to represent None in Python
}

typedef struct {
    double decay_rate;
    double current_reward;
} RewardCalculator;

void RewardCalculator_init(RewardCalculator *self, double decay_rate) {
    self->decay_rate = decay_rate;
    self->current_reward = 1.0;
}

double RewardCalculator_calculate(RewardCalculator *self) {
    self->current_reward *= self->decay_rate;
    return self->current_reward;
}

double process_sequence() {
    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, 1, 10, 1);
    RewardCalculator reward_calc;
    RewardCalculator_init(&reward_calc, 0.95);
    double total_reward = 0.0;
    while (1) {
        int value = SequenceGenerator_generate(&seq_gen);
        if (value == -1) {
            break;
        }
        double reward = RewardCalculator_calculate(&reward_calc);
        total_reward += reward;
    }
    return total_reward;
}

void main() {
    double result = process_sequence();
    printf("%f\n", result);
}