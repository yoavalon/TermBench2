#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISCOUNT_FACTOR 0.9

typedef struct {
    int state;
} Agent;

typedef struct {
    int action_space[2];
} Environment;

typedef struct {
    Agent agent;
    Environment environment;
    double total_reward;
} Simulator;

void agent_init(Agent *agent) {
    agent->state = 0;
}

int agent_take_action(Agent *agent) {
    return rand() % 2;
}

double agent_receive_reward(Agent *agent, int action) {
    return (action == 1) ? 1.0 : 0.0;
}

void agent_update_state(Agent *agent, int action) {
    if (action == 1) {
        agent->state++;
    } else {
        agent->state--;
    }
}

void environment_init(Environment *environment) {
    environment->action_space[0] = 0;
    environment->action_space[1] = 1;
}

int* environment_get_possible_actions(Environment *environment) {
    return environment->action_space;
}

void simulator_init(Simulator *simulator) {
    agent_init(&simulator->agent);
    environment_init(&simulator->environment);
    simulator->total_reward = 0.0;
}

double simulator_run_step(Simulator *simulator) {
    int action = agent_take_action(&simulator->agent);
    double reward = agent_receive_reward(&simulator->agent, action) * pow(DISCOUNT_FACTOR, simulator->agent.state);
    simulator->total_reward += reward;
    agent_update_state(&simulator->agent, action);
    return reward;
}

void simulator_simulate(Simulator *simulator) {
    while (1) {
        simulator_run_step(simulator);
    }
}

int main() {
    srand(time(0));
    Simulator simulator;
    simulator_init(&simulator);
    simulator_simulate(&simulator);
    return 0;
}