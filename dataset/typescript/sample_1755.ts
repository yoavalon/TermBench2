class Environment {
    state: number;
    reward: number;
    decay_rate: number;

    constructor() {
        this.state = 0;
        this.reward = 1.0;
        this.decay_rate = 0.99;
    }

    step(action: number): [number, number] {
        if (action == 1) {
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
    action: number;

    constructor() {
        this.action = 1;
    }

    decide(): number {
        return this.action;
    }
}

class Simulation {
    env: Environment;
    agent: Agent;

    constructor(env: Environment, agent: Agent) {
        this.env = env;
        this.agent = agent;
    }

    run(): void {
        while (true) {
            const action = this.agent.decide();
            const [state, reward] = this.env.step(action);
            console.log(`State: ${state}, Reward: ${reward.toFixed(4)}`);
        }
    }
}

function main(): void {
    const env = new Environment();
    const agent = new Agent();
    const sim = new Simulation(env, agent);
    sim.run();
}

main();