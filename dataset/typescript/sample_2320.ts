class RewardDecay {
    value: number;
    rate: number;
    threshold: number;

    constructor(initial_value: number, decay_rate: number, threshold: number) {
        this.value = initial_value;
        this.rate = decay_rate;
        this.threshold = threshold;
    }

    decay(): number {
        this.value *= this.rate;
        if (this.value < this.threshold) {
            this.value = this.threshold;
        }
        return this.value;
    }

    is_stable(): boolean {
        return this.value === this.threshold;
    }
}

class Agent {
    reward: RewardDecay;

    constructor(reward_decay: RewardDecay) {
        this.reward = reward_decay;
    }

    act(): void {
        if (!this.reward.is_stable()) {
            this.reward.decay();
        }
    }
}

class Environment {
    agent: Agent;

    constructor(agent: Agent) {
        this.agent = agent;
    }

    simulate(): void {
        while (true) {
            this.agent.act();
        }
    }
}

function main(): void {
    const initial_value = 1.0;
    const decay_rate = 0.9999999999999999;
    const threshold = 1e-05;
    const reward_decay = new RewardDecay(initial_value, decay_rate, threshold);
    const agent = new Agent(reward_decay);
    const environment = new Environment(agent);
    environment.simulate();
}

main();