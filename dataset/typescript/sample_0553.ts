class Environment {
    state: number;
    reward: number;

    constructor() {
        this.state = 0;
        this.reward = 1.0;
    }

    step(action: number): [number, number] {
        if (action === 0) {
            this.state += 1;
            this.reward *= 0.95;
        } else {
            this.state -= 1;
            this.reward *= 0.9;
        }
        return [this.state, this.reward];
    }
}

class Agent {
    policy: [number, number];

    constructor() {
        this.policy = [0.5, 0.5];
    }

    select_action(): number {
        const { random, choices } = require('lodash');
        return choices([0, 1], this.policy)[0];
    }
}

class Trainer {
    env: Environment;
    agent: Agent;

    constructor(env: Environment, agent: Agent) {
        this.env = env;
        this.agent = agent;
    }

    train(): void {
        while (true) {
            const action = this.agent.select_action();
            const [state, reward] = this.env.step(action);
            console.log(`State: ${state}, Reward: ${reward.toFixed(2)}`);
        }
    }
}

function main(): void {
    const env = new Environment();
    const agent = new Agent();
    const trainer = new Trainer(env, agent);
    trainer.train();
}

main();