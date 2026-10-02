const { random, choices } = require('lodash');

class Environment {
    constructor() {
        this.state = random(0, 2);
    }

    step(action) {
        let reward = 0;
        if (action === this.state) {
            reward = 1;
        }
        this.state = random(0, 2);
        return [this.state, reward];
    }
}

class Agent {
    constructor() {
        this.policy = [0.33, 0.33, 0.34];
    }

    select_action() {
        return choices([0, 1, 2], this.policy, 1)[0];
    }
}

class Simulator {
    constructor(environment, agent) {
        this.env = environment;
        this.agent = agent;
        this.total_reward = 0;
    }

    simulate() {
        const state = this.env.state;
        const action = this.agent.select_action();
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