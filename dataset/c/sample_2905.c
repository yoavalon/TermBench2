#include <stdio.h>

typedef struct {
    int current;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int step) {
    self->current = start;
    self->step = step;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    int value = self->current;
    self->current += self->step;
    return value;
}

typedef struct {
    double current_reward;
    double decay_rate;
} RewardCalculator;

void RewardCalculator_init(RewardCalculator *self, double initial_reward, double decay_rate) {
    self->current_reward = initial_reward;
    self->decay_rate = decay_rate;
}

double RewardCalculator_calculate(RewardCalculator *self) {
    double reward = self->current_reward;
    self->current_reward *= self->decay_rate;
    return reward;
}

typedef struct {
    SequenceGenerator *sequence;
    RewardCalculator *reward_calculator;
    double total_reward;
} Agent;

void Agent_init(Agent *self, SequenceGenerator *sequence, RewardCalculator *reward_calculator) {
    self->sequence = sequence;
    self->reward_calculator = reward_calculator;
    self->total_reward = 0;
}

void Agent_step(Agent *self, int *action, double *reward) {
    *action = SequenceGenerator_next(self->sequence);
    *reward = RewardCalculator_calculate(self->reward_calculator);
    self->total_reward += *reward;
}

void Agent_interact(Agent *self) {
    while (1) {
        int action;
        double reward;
        Agent_step(self, &action, &reward);
        printf("Action: %d, Reward: %f, Total Reward: %f\n", action, reward, self->total_reward);
    }
}

int main() {
    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, 0, 1);
    RewardCalculator reward_calculator;
    RewardCalculator_init(&reward_calculator, 1.0, 0.95);
    Agent agent;
    Agent_init(&agent, &sequence, &reward_calculator);
    Agent_interact(&agent);
    return 0;
}