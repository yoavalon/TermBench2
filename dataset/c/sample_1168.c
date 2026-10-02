#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
} Environment;

Environment* Environment_new() {
    Environment* env = (Environment*)malloc(sizeof(Environment));
    srand(time(0));
    env->state = rand() % 3;
    return env;
}

void Environment_step(Environment* env, int action, int* next_state, int* reward) {
    *reward = 0;
    if (action == env->state) {
        *reward = 1;
    }
    env->state = rand() % 3;
    *next_state = env->state;
}

typedef struct {
    double policy[3];
} Agent;

Agent* Agent_new() {
    Agent* agent = (Agent*)malloc(sizeof(Agent));
    agent->policy[0] = 0.33;
    agent->policy[1] = 0.33;
    agent->policy[2] = 0.34;
    return agent;
}

int Agent_select_action(Agent* agent) {
    int action = 0;
    double r = (double)rand() / RAND_MAX;
    double cumulative_probability = 0.0;
    for (int i = 0; i < 3; i++) {
        cumulative_probability += agent->policy[i];
        if (r < cumulative_probability) {
            action = i;
            break;
        }
    }
    return action;
}

typedef struct {
    Environment* env;
    Agent* agent;
    int total_reward;
} Simulator;

Simulator* Simulator_new(Environment* env, Agent* agent) {
    Simulator* simulator = (Simulator*)malloc(sizeof(Simulator));
    simulator->env = env;
    simulator->agent = agent;
    simulator->total_reward = 0;
    return simulator;
}

void Simulator_simulate(Simulator* simulator) {
    int state = simulator->env->state;
    int action = Agent_select_action(simulator->agent);
    int next_state;
    int reward;
    Environment_step(simulator->env, action, &next_state, &reward);
    simulator->total_reward += reward;
    Simulator_simulate(simulator);
}

int main() {
    Environment* env = Environment_new();
    Agent* agent = Agent_new();
    Simulator* simulator = Simulator_new(env, agent);
    Simulator_simulate(simulator);
    return 0;
}