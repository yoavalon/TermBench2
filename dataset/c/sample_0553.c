c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    double reward;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->reward = 1.0;
}

void Environment_step(Environment *env, int action, int *new_state, double *new_reward) {
    if (action == 0) {
        env->state += 1;
        env->reward *= 0.95;
    } else {
        env->state -= 1;
        env->reward *= 0.9;
    }
    *new_state = env->state;
    *new_reward = env->reward;
}

typedef struct {
    double policy[2];
} Agent;

void Agent_init(Agent *agent) {
    agent->policy[0] = 0.5;
    agent->policy[1] = 0.5;
}

int Agent_select_action(Agent *agent) {
    double r = ((double)rand() / RAND_MAX);
    if (r < agent->policy[0]) {
        return 0;
    } else {
        return 1;
    }
}

typedef struct {
    Environment *env;
    Agent *agent;
} Trainer;

void Trainer_init(Trainer *trainer, Environment *env, Agent *agent) {
    trainer->env = env;
    trainer->agent = agent;
}

void Trainer_train(Trainer *trainer) {
    int state;
    double reward;
    while (1) {
        int action = Agent_select_action(trainer->agent);
        Environment_step(trainer->env, action, &state, &reward);
        printf("State: %d, Reward: %.2f\n", state, reward);
    }
}

int main() {
    srand(time(NULL));
    Environment env;
    Agent agent;
    Trainer trainer;
    Environment_init(&env);
    Agent_init(&agent);
    Trainer_init(&trainer, &env, &agent);
    Trainer_train(&trainer);
    return 0;
}