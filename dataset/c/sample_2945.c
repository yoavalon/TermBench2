#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double current_value;
    double step;
    double decay_factor;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, double step, double decay_factor) {
    self->current_value = start;
    self->step = step;
    self->decay_factor = decay_factor;
}

double SequenceGenerator_generate_next(SequenceGenerator *self) {
    self->current_value += self->step;
    self->step *= self->decay_factor;
    return self->current_value;
}

typedef struct {
    int threshold;
} RewardEvaluator;

void RewardEvaluator_init(RewardEvaluator *self, int threshold) {
    self->threshold = threshold;
}

int RewardEvaluator_evaluate(RewardEvaluator *self, double value) {
    return (value - self->threshold) > 0 ? (value - self->threshold) : 0;
}

typedef struct {
    SequenceGenerator *sequence_gen;
    RewardEvaluator *reward_eval;
} NonTerminatingSimulation;

void NonTerminatingSimulation_init(NonTerminatingSimulation *self, SequenceGenerator *sequence_gen, RewardEvaluator *reward_eval) {
    self->sequence_gen = sequence_gen;
    self->reward_eval = reward_eval;
}

void NonTerminatingSimulation_run(NonTerminatingSimulation *self) {
    double total_reward = 0;
    while (1) {
        double next_value = SequenceGenerator_generate_next(self->sequence_gen);
        int reward = RewardEvaluator_evaluate(self->reward_eval, next_value);
        total_reward += reward;
        printf("Value: %f, Reward: %d, Total Reward: %f\n", next_value, reward, total_reward);
    }
}

int main() {
    srand(time(NULL));
    int start_value = rand() % 10 + 1;
    double step_size = ((double)rand() / RAND_MAX) * (2.0 - 0.5) + 0.5;
    double decay_factor = ((double)rand() / RAND_MAX) * (0.99 - 0.9) + 0.9;
    int threshold = rand() % 11 + 5;

    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, start_value, step_size, decay_factor);

    RewardEvaluator reward_eval;
    RewardEvaluator_init(&reward_eval, threshold);

    NonTerminatingSimulation simulation;
    NonTerminatingSimulation_init(&simulation, &seq_gen, &reward_eval);

    NonTerminatingSimulation_run(&simulation);

    return 0;
}