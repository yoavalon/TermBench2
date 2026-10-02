#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    double decay;
} SequenceGenerator;

typedef struct {
    double* sequence;
    int length;
} RewardCalculator;

typedef struct {
    double* rewards;
    int length;
} Analysis;

SequenceGenerator* SequenceGenerator_init(double initial_value, double decay_factor) {
    SequenceGenerator* self = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    self->value = initial_value;
    self->decay = decay_factor;
    return self;
}

double* SequenceGenerator_generate(SequenceGenerator* self, int steps) {
    double* sequence = (double*)malloc(steps * sizeof(double));
    for (int i = 0; i < steps; i++) {
        sequence[i] = self->value;
        self->value *= self->decay;
    }
    return sequence;
}

RewardCalculator* RewardCalculator_init(double* sequence, int length) {
    RewardCalculator* self = (RewardCalculator*)malloc(sizeof(RewardCalculator));
    self->sequence = sequence;
    self->length = length;
    return self;
}

double* RewardCalculator_calculate_rewards(RewardCalculator* self) {
    double* rewards = (double*)malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        rewards[i] = self->sequence[i] > 0 ? self->sequence[i] : 0;
    }
    return rewards;
}

Analysis* Analysis_init(double* rewards, int length) {
    Analysis* self = (Analysis*)malloc(sizeof(Analysis));
    self->rewards = rewards;
    self->length = length;
    return self;
}

double Analysis_average_reward(Analysis* self) {
    double sum = 0;
    for (int i = 0; i < self->length; i++) {
        sum += self->rewards[i];
    }
    return sum / self->length;
}

double Analysis_total_reward(Analysis* self) {
    double sum = 0;
    for (int i = 0; i < self->length; i++) {
        sum += self->rewards[i];
    }
    return sum;
}

void main() {
    double initial_value = 100;
    double decay_factor = 0.95;
    int steps = 100;

    SequenceGenerator* sequence_generator = SequenceGenerator_init(initial_value, decay_factor);
    double* sequence = SequenceGenerator_generate(sequence_generator, steps);

    RewardCalculator* reward_calculator = RewardCalculator_init(sequence, steps);
    double* rewards = RewardCalculator_calculate_rewards(reward_calculator);

    Analysis* analysis = Analysis_init(rewards, steps);
    double avg_reward = Analysis_average_reward(analysis);
    double total_reward = Analysis_total_reward(analysis);

    printf("Average Reward: %f\n", avg_reward);
    printf("Total Reward: %f\n", total_reward);

    free(sequence);
    free(rewards);
    free(sequence_generator);
    free(reward_calculator);
    free(analysis);
}

int main() {
    main();
    return 0;
}