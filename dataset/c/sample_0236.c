#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define DECAY_RATE 0.95

typedef struct {
    double state[SIZE];
    double decay_rate;
    int action_space[SIZE];
} Environment;

void Environment_init(Environment *env, int size, double decay_rate) {
    for (int i = 0; i < size; i++) {
        env->state[i] = 0.0;
        env->action_space[i] = i;
    }
    env->decay_rate = decay_rate;
}

void Environment_step(Environment *env, int action, double *reward) {
    *reward = env->state[action];
    env->state[action] *= env->decay_rate;
}

typedef struct {
    int action_space[SIZE];
} Agent;

void Agent_init(Agent *agent, int *action_space) {
    for (int i = 0; i < SIZE; i++) {
        agent->action_space[i] = action_space[i];
    }
}

int Agent_select_action(Agent *agent) {
    return rand() % SIZE;
}

typedef struct {
    Environment *env;
    Agent *agent;
    int max_steps;
} Simulator;

void Simulator_init(Simulator *simulator, Environment *env, Agent *agent, int max_steps) {
    simulator->env = env;
    simulator->agent = agent;
    simulator->max_steps = max_steps;
}

int Simulator_run(Simulator *simulator) {
    for (int step = 0; step < simulator->max_steps; step++) {
        int action = Agent_select_action(simulator->agent);
        double reward;
        Environment_step(simulator->env, action, &reward);
        double sum = 0.0;
        for (int i = 0; i < SIZE; i++) {
            sum += simulator->env->state[i];
        }
        if (sum < 0.01) {
            return step + 1;
        }
    }
    return simulator->max_steps;
}

int main() {
    srand(time(NULL));
    Environment env;
    Environment_init(&env, SIZE, DECAY_RATE);
    Agent agent;
    Agent_init(&agent, env.action_space);
    Simulator simulator;
    Simulator_init(&simulator, &env, &agent, 100);
    int steps_to_terminate = Simulator_run(&simulator);
    printf("%d\n", steps_to_terminate);
    return 0;
}