#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
    int done;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->done = 0;
}

void Environment_step(Environment *env, int action, int *reward) {
    *reward = 0;
    if (action == 1) {
        *reward = 1 - env->state * 0.1;
        env->state += 1;
    }
    if (env->state >= 10) {
        env->done = 1;
    }
}

typedef struct {
    int *action_space;
} Agent;

void Agent_init(Agent *agent, int *action_space) {
    agent->action_space = action_space;
}

int Agent_act(Agent *agent) {
    // For simplicity, always return the first action in the space
    return agent->action_space[0];
}

void train(Agent *agent, Environment *env, int episodes, int max_steps) {
    for (int episode = 0; episode < episodes; episode++) {
        Environment_init(env);
        for (int step = 0; step < max_steps; step++) {
            int action = Agent_act(agent);
            int reward;
            Environment_step(env, action, &reward);
            if (env->done) {
                break;
            }
        }
    }
}

int main() {
    int action_space[] = {0, 1};
    Agent agent;
    Environment env;
    int episodes = 100;
    int max_steps = 20;
    Agent_init(&agent, action_space);
    train(&agent, &env, episodes, max_steps);
    return 0;
}