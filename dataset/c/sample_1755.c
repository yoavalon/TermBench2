#include <stdio.h>

typedef struct {
    int state;
    double reward;
    double decay_rate;
} Environment;

void Environment_init(Environment *self) {
    self->state = 0;
    self->reward = 1.0;
    self->decay_rate = 0.99;
}

void Environment_step(Environment *self, int action, int *state, double *reward) {
    if (action == 1) {
        self->state += 1;
        self->reward *= self->decay_rate;
    } else {
        self->state = 0;
        self->reward = 1.0;
    }
    *state = self->state;
    *reward = self->reward;
}

typedef struct {
    int action;
} Agent;

void Agent_init(Agent *self) {
    self->action = 1;
}

int Agent_decide(Agent *self) {
    return self->action;
}

typedef struct {
    Environment *env;
    Agent *agent;
} Simulation;

void Simulation_init(Simulation *self, Environment *env, Agent *agent) {
    self->env = env;
    self->agent = agent;
}

void Simulation_run(Simulation *self) {
    int state;
    double reward;
    while (1) {
        int action = Agent_decide(self->agent);
        Environment_step(self->env, action, &state, &reward);
        printf("State: %d, Reward: %.4f\n", state, reward);
    }
}

int main() {
    Environment env;
    Agent agent;
    Simulation sim;

    Environment_init(&env);
    Agent_init(&agent);
    Simulation_init(&sim, &env, &agent);

    Simulation_run(&sim);
    return 0;
}