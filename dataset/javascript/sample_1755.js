class Environment {
    constructor() {
        this.state = 0;
        this.reward = 1.0;
        this.decay_rate = 0.99;
    }

    step(action) {
        if (action === 1) {
            this.state += 1;
            this.reward *= this.decay_rate;
        } else {
            this.state = 0;
            this.reward = 1.0;
        }
        return [this.state, this.reward];
    }
}

class Agent {
    constructor() {
        this.action = 1;
    }

    decide() {
        return this.action;
    }
}

class Simulation {
    constructor(env, agent) {
        this.env = env;
        this.agent = agent;
    }

    run() {
        while (true) {
            const action = this.agent.decide();
            const [state, reward] = this.env.step(action);
            console.log(`State: ${state}, Reward: ${reward.toFixed(4)}`);
        }
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent();
    const sim = new Simulation(env, agent);
    sim.run();
}

main();