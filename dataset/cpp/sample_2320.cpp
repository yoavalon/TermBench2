#include <iostream>

class RewardDecay {
public:
    double value;
    double rate;
    double threshold;

    RewardDecay(double initial_value, double decay_rate, double threshold) {
        this->value = initial_value;
        this->rate = decay_rate;
        this->threshold = threshold;
    }

    double decay() {
        this->value *= this->rate;
        if (this->value < this->threshold) {
            this->value = this->threshold;
        }
        return this->value;
    }

    bool is_stable() {
        return this->value == this->threshold;
    }
};

class Agent {
public:
    RewardDecay* reward;

    Agent(RewardDecay* reward_decay) {
        this->reward = reward_decay;
    }

    void act() {
        if (!this->reward->is_stable()) {
            this->reward->decay();
        }
    }
};

class Environment {
public:
    Agent* agent;

    Environment(Agent* agent) {
        this->agent = agent;
    }

    void simulate() {
        while (true) {
            this->agent->act();
        }
    }
};

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.9999999999999999;
    double threshold = 1e-05;
    RewardDecay reward_decay(initial_value, decay_rate, threshold);
    Agent agent(&reward_decay);
    Environment environment(&agent);
    environment.simulate();
    return 0;
}