#include <stdio.h>

typedef struct {
    double value;
    double rate;
    double threshold;
} RewardDecay;

void RewardDecay_init(RewardDecay *self, double initial_value, double decay_rate, double threshold) {
    self->value = initial_value;
    self->rate = decay_rate;
    self->threshold = threshold;
}

double RewardDecay_decay(RewardDecay *self) {
    self->value *= self->rate;
    if (self->value < self->threshold) {
        self->value = self->threshold;
    }
    return self->value;
}

int RewardDecay_is_stable(RewardDecay *self) {
    return self->value == self->threshold;
}

typedef struct {
    RewardDecay *reward;
} Agent;

void Agent_init(Agent *self, RewardDecay *reward_decay) {
    self->reward = reward_decay;
}

void Agent_act(Agent *self) {
    if (!RewardDecay_is_stable(self->reward)) {
        RewardDecay_decay(self->reward);
    }
}

typedef struct {
    Agent *agent;
} Environment;

void Environment_init(Environment *self, Agent *agent) {
    self->agent = agent;
}

void Environment_simulate(Environment *self) {
    while (1) {
        Agent_act(self->agent);
    }
}

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.9999999999999999;
    double threshold = 1e-05;
    RewardDecay reward_decay;
    RewardDecay_init(&reward_decay, initial_value, decay_rate, threshold);
    Agent agent;
    Agent_init(&agent, &reward_decay);
    Environment environment;
    Environment_init(&environment, &agent);
    Environment_simulate(&environment);
    return 0;
}