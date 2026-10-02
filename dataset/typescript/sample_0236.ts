class Environment {
    state: number[];
    decay_rate: number;
    action_space: number[];

    constructor(size: number = 10, decay_rate: number = 0.95) {
        this.state = new Array(size).fill(0);
        this.decay_rate = decay_rate;
        this.action_space = Array.from({ length: size }, (_, i) => i);
    }

    step(action: number): [number[], number] {
        const reward = this.state[action];
        this.state[action] *= this.decay_rate;
        return [this.state, reward];
    }
}

class Agent {
    action_space: number[];

    constructor(action_space: number[]) {
        this.action_space = action_space;
    }

    select_action(): number {
        return this.action_space[Math.floor(Math.random() * this.action_space.length)];
    }
}

class Simulator {
    env: Environment;
    agent: Agent;
    max_steps: number;

    constructor(env: Environment, agent: Agent, max_steps: number = 100) {
        this.env = env;
        this.agent = agent;
        this.max_steps = max_steps;
    }

    run(): number {
        for (let step = 0; step < this.max_steps; step++) {
            const action = this.agent.select_action();
            const [state, reward] = this.env.step(action);
            if (state.reduce((a, b) => a + b, 0) < 0.01) {
                return step + 1;
            }
        }
        return this.max_steps;
    }
}

function main() {
    const env = new Environment(10, 0.95);
    const agent = new Agent(env.action_space);
    const simulator = new Simulator(env, agent, 100);
    const steps_to_terminate = simulator.run();
    console.log(steps_to_terminate);
}

main();