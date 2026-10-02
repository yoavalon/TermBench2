#include <stdio.h>
#include <math.h>

typedef struct {
    double value;
    double decay_rate;
} SequenceGenerator;

typedef struct {
    double base_reward;
    double decay_factor;
} RewardCalculator;

typedef struct {
    SequenceGenerator *sequence;
    RewardCalculator *reward;
    int step;
} Simulation;

void SequenceGenerator_init(SequenceGenerator *self, double initial_value, double decay_rate) {
    self->value = initial_value;
    self->decay_rate = decay_rate;
}

double SequenceGenerator_generate_next(SequenceGenerator *self) {
    self->value *= self->decay_rate;
    return self->value;
}

void RewardCalculator_init(RewardCalculator *self, double base_reward, double decay_factor) {
    self->base_reward = base_reward;
    self->decay_factor = decay_factor;
}

double RewardCalculator_calculate_reward(RewardCalculator *self, int step) {
    return self->base_reward * pow(self->decay_factor, step);
}

void Simulation_init(Simulation *self, SequenceGenerator *sequence, RewardCalculator *reward) {
    self->sequence = sequence;
    self->reward = reward;
    self->step = 0;
}

void Simulation_run(Simulation *self) {
    while (1) {
        double current_value = SequenceGenerator_generate_next(self->sequence);
        double current_reward = RewardCalculator_calculate_reward(self->reward, self->step);
        printf("Step %d: Value=%.4f, Reward=%.4f\n", self->step, current_value, current_reward);
        self->step += 1;
    }
}

int main() {
    double initial_value = 100.0;
    double decay_rate = 0.95;
    double base_reward = 10.0;
    double decay_factor = 0.9;

    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, initial_value, decay_rate);

    RewardCalculator reward;
    RewardCalculator_init(&reward, base_reward, decay_factor);

    Simulation simulation;
    Simulation_init(&simulation, &sequence, &reward);

    Simulation_run(&simulation);

    return 0;
}