#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int state;
    int action_space[2];
} Environment;

typedef struct {
    int* action_space;
    double epsilon;
} Agent;

Environment* Environment_init() {
    Environment* env = (Environment*)malloc(sizeof(Environment));
    env->state = rand() % 10;
    env->action_space[0] = 0;
    env->action_space[1] = 1;
    return env;
}

void Environment_step(Environment* env, int action, int* next_state, double* reward, int* done) {
    if (action == 0) {
        *reward = 1 - (double)env->state / 10.0;
    } else {
        *reward = (double)env->state / 10.0;
    }
    env->state = rand() % 10;
    *next_state = env->state;
    *done = (rand() / (double)RAND_MAX) < 0.05;
}

Agent* Agent_init(int* action_space) {
    Agent* agent = (Agent*)malloc(sizeof(Agent));
    agent->action_space = action_space;
    agent->epsilon = 1.0;
    return agent;
}

int Agent_choose_action(Agent* agent, int state) {
    if ((rand() / (double)RAND_MAX) < agent->epsilon) {
        return agent->action_space[rand() % 2];
    } else {
        return Agent_policy(agent, state);
    }
}

int Agent_policy(Agent* agent, int state) {
    return state < 5 ? 0 : 1;
}

void train(Agent* agent, Environment* env, int episodes) {
    for (int episode = 0; episode < episodes; episode++) {
        int state = env->state;
        int done = 0;
        while (!done) {
            int action = Agent_choose_action(agent, state);
            int next_state;
            double reward;
            Environment_step(env, action, &next_state, &reward, &done);
            state = next_state;
        }
        agent->epsilon = fmax(0.01, agent->epsilon * 0.99);
    }
}

int main() {
    srand(time(NULL));
    Environment* env = Environment_init();
    Agent* agent = Agent_init(env->action_space);
    int episodes = 1000;
    train(agent, env, episodes);
    free(env);
    free(agent);
    return 0;
}