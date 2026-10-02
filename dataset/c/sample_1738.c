#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char state;
    char goal_state;
} Environment;

typedef struct {
    Environment *env;
    char action;
} Agent;

typedef struct {
    Agent *agent;
    int total_reward;
} Controller;

void Environment_init(Environment *self) {
    srand(time(NULL));
    self->state = "ABC"[rand() % 3];
    self->goal_state = 'C';
}

int Environment_step(Environment *self, char action) {
    if (action == 'm') {
        if (self->state == 'A') {
            self->state = 'B';
        } else if (self->state == 'B') {
            self->state = 'C';
        }
        return self->_reward(self);
    }
    return 0;
}

int Environment__reward(Environment *self) {
    return self->state == self->goal_state ? 1 : 0;
}

void Agent_init(Agent *self, Environment *env) {
    self->env = env;
    self->action = 'm';
}

void Agent_act(Agent *self) {
    int reward = Environment_step(self->env, self->action);
    printf("Current state: %c, Reward: %d\n", self->env->state, reward);
}

void Controller_init(Controller *self, Agent *agent) {
    self->agent = agent;
    self->total_reward = 0;
}

void Controller_run(Controller *self) {
    while (1) {
        Agent_act(self->agent);
        if (self->agent->env->state == self->agent->env->goal_state) {
            printf("Goal reached with total reward: %d\n", self->total_reward);
        }
    }
}

int main() {
    Environment env;
    Agent agent;
    Controller controller;

    Environment_init(&env);
    Agent_init(&agent, &env);
    Controller_init(&controller, &agent);

    Controller_run(&controller);

    return 0;
}