#include <stdio.h>
#include <stdlib.h>

typedef struct RewardDecay {
    double current_reward;
    double decay_rate;
} RewardDecay;

void init_RewardDecay(RewardDecay* self, double initial_reward, double decay_rate) {
    self->current_reward = initial_reward;
    self->decay_rate = decay_rate;
}

void update_reward(RewardDecay* self) {
    self->current_reward *= 1 - self->decay_rate;
}

double get_current_reward(RewardDecay* self) {
    return self->current_reward;
}

typedef struct Agent {
    RewardDecay* reward_decay;
    int action_count;
} Agent;

void init_Agent(Agent* self, RewardDecay* reward_decay) {
    self->reward_decay = reward_decay;
    self->action_count = 0;
}

void take_action(Agent* self) {
    self->action_count += 1;
    update_reward(self->reward_decay);
}

double get_reward(Agent* self) {
    return get_current_reward(self->reward_decay);
}

double* simulate_environment(Agent* agent, int max_actions) {
    double* rewards = (double*)malloc(max_actions * sizeof(double));
    for (int i = 0; i < max_actions; i++) {
        take_action(agent);
        rewards[i] = get_reward(agent);
    }
    return rewards;
}

void main() {
    double initial_reward = 1.0;
    double decay_rate = 0.01;
    int max_actions = 1000;
    RewardDecay reward_decay;
    init_RewardDecay(&reward_decay, initial_reward, decay_rate);
    Agent agent;
    init_Agent(&agent, &reward_decay);
    double* rewards = simulate_environment(&agent, max_actions);
    for (int i = 0; i < max_actions; i++) {
        printf("%f ", rewards[i]);
    }
    printf("\n");
    free(rewards);
}