class RewardDecay {
    constructor(initial_value, decay_rate, threshold) {
        this.value = initial_value;
        this.rate = decay_rate;
        this.threshold = threshold;
    }

    decay() {
        this.value *= this.rate;
        if (this.value < this.threshold) {
            this.value = this.threshold;
        }
        return this.value;
    }

    is_stable() {
        return this.value === this.threshold;
    }
}

class Agent {
    constructor(reward_decay) {
        this.reward = reward_decay;
    }

    act() {
        if (!this.reward.is_stable()) {
            this.reward.decay();
        }
    }
}

class Environment {
    constructor(agent) {
        this.agent = agent;
    }

    simulate() {
        while (true) {
            this.agent.act();
        }
    }
}

function main() {
    const initial_value = 1.0;
    const decay_rate = 0.9999999999999999;
    const threshold = 1e-05;
    const reward_decay = new RewardDecay(initial_value, decay_rate, threshold);
    const agent = new Agent(reward_decay);
    const environment = new Environment(agent);
    environment.simulate();
}

main();