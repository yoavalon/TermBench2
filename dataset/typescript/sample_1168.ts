import * as random from 'random-js';

class Environment {
    state: number;

    constructor() {
        this.state = random.integer(0, 2)();
    }

    step(action: number): [number, number] {
        let reward = 0;
        if (action === this.state) {
            reward = 1;
        }
        this.state = random.integer(0, 2)();
        return [this.state, reward];
    }
}

class Agent {
    policy: number[];

    constructor() {
        this.policy = [0.33, 0.33, 0.34];
    }

    select_action(): number {
        const weights = this.policy;
        const actions = [0, 1, 2];
        const total = weights.reduce((acc, val) => acc + val, 0);
        let r = random.real(0, total)();
        for (let i = 0; i < actions.length; i++) {
            r -= weights[i];
            if (r <= 0) {
                return actions[i];
            }
        }
        return actions[actions.length - 1];
    }
}

class Simulator {
    env: Environment;
    agent: Agent;
    total_reward: number;

    constructor(environment: Environment, agent: Agent) {
        this.env = environment;
        this.agent = agent;
        this.total_reward = 0;
    }

    simulate() {
        const [state, action] = [this.env.state, this.agent.select_action()];
        const [next_state, reward] = this.env.step(action);
        this.total_reward += reward;
        this.simulate();
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent();
    const simulator = new Simulator(env, agent);
    simulator.simulate();
}

main();