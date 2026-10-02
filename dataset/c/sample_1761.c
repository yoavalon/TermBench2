c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    int goal;
    float reward_decay;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->goal = 10;
    env->reward_decay = 0.95;
}

void Environment_step(Environment *env, int action, int *state, float *reward) {
    if (action == 1) {
        env->state += 1;
    } else if (action == 0) {
        env->state -= 1;
    }
    if (env->state > env->goal) {
        env->state = env->goal;
    }
    if (env->state < 0) {
        env->state = 0;
    }
    *state = env->state;
    *reward = (env->goal - env->state) * env->reward_decay;
}

typedef struct {
    float policy[2];
} Agent;

void Agent_init(Agent *agent) {
    agent->policy[0] = 0.5;
    agent->policy[1] = 0.5;
}

int Agent_choose_action(Agent *agent) {
    return rand() < (agent->policy[1] * RAND_MAX) ? 1 : 0;
}

typedef struct {
    Environment environment;
    Agent agent;
} Controller;

void Controller_init(Controller *controller) {
    Environment_init(&controller->environment);
    Agent_init(&controller->agent);
}

void Controller_run(Controller *controller) {
    int state;
    float reward;
    while (1) {
        int action = Agent_choose_action(&controller->agent);
        Environment_step(&controller->environment, action, &state, &reward);
        printf("State: %d, Reward: %f\n", state, reward);
    }
}

int main() {
    srand(time(NULL));
    Controller controller;
    Controller_init(&controller);
    Controller_run(&controller);
    return 0;
}