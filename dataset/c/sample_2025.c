#include <stdio.h>

typedef struct {
    double value;
    double decay_rate;
} RewardSystem;

void init_reward_system(RewardSystem *rs, double initial_value, double decay_rate) {
    rs->value = initial_value;
    rs->decay_rate = decay_rate;
}

double decay(RewardSystem *rs) {
    rs->value *= rs->decay_rate;
    return rs->value;
}

typedef struct {
    RewardSystem *reward_system;
} Environment;

void init_environment(Environment *env, RewardSystem *reward_system) {
    env->reward_system = reward_system;
}

double step(Environment *env) {
    return decay(env->reward_system);
}

typedef struct {
    Environment *environment;
} Agent;

void init_agent(Agent *agent, Environment *environment) {
    agent->environment = environment;
}

double act(Agent *agent) {
    return step(agent->environment);
}

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.99;
    RewardSystem reward_system;
    init_reward_system(&reward_system, initial_value, decay_rate);
    Environment environment;
    init_environment(&environment, &reward_system);
    Agent agent;
    init_agent(&agent, &environment);
    double threshold = 0.01;
    int iterations = 0;
    while (1) {
        double reward = act(&agent);
        iterations += 1;
        if (reward < threshold) {
            break;
        }
    }
    printf("Terminated after %d iterations with reward %.6f\n", iterations, reward);
    return 0;
}