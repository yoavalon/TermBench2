#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ENV_SIZE 5
#define EPISODES 50
#define DECAY_RATE 0.9

typedef struct {
    double state[ENV_SIZE];
} Environment;

typedef struct {
    int action_space[ENV_SIZE];
} Agent;

void Environment_init(Environment *env, int size) {
    for (int i = 0; i < size; i++) {
        env->state[i] = 0.0;
    }
}

void Environment_reset(Environment *env) {
    for (int i = 0; i < ENV_SIZE; i++) {
        env->state[i] = 0.0;
    }
}

void Environment_step(Environment *env, int action, double *reward, int *done) {
    *reward = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Normal distribution approximation
    env->state[action] += 1.0;
    *done = 0;
    for (int i = 0; i < ENV_SIZE; i++) {
        if (env->state[i] > 10.0) {
            *done = 1;
            break;
        }
    }
}

void Agent_init(Agent *agent, int size) {
    for (int i = 0; i < size; i++) {
        agent->action_space[i] = i;
    }
}

int Agent_choose_action(Agent *agent) {
    return agent->action_space[rand() % ENV_SIZE];
}

void train_agent(Environment *env, Agent *agent, int episodes, double decay_rate) {
    double rewards[episodes];
    for (int episode = 0; episode < episodes; episode++) {
        Environment_reset(env);
        double total_reward = 0.0;
        for (int step = 0; step < 100; step++) {
            int action = Agent_choose_action(agent);
            double reward;
            int done;
            Environment_step(env, action, &reward, &done);
            total_reward += reward;
            if (done) {
                break;
            }
        }
        rewards[episode] = total_reward;
        if (episode > 0 && episode % 10 == 0) {
            for (int i = 0; i < episode; i++) {
                rewards[i] *= decay_rate;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Environment env;
    Agent agent;
    Environment_init(&env, ENV_SIZE);
    Agent_init(&agent, ENV_SIZE);
    train_agent(&env, &agent, EPISODES, DECAY_RATE);
    return 0;
}