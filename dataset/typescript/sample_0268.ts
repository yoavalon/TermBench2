class Environment {
    state: number;
    done: boolean;

    constructor() {
        this.state = 0;
        this.done = false;
    }

    step(action: number): [number, number, boolean] {
        let reward = 0;
        if (action === 1) {
            reward = 1 - this.state * 0.1;
            this.state += 1;
        }
        if (this.state >= 10) {
            this.done = true;
        }
        return [this.state, reward, this.done];
    }

    reset(): void {
        this.state = 0;
        this.done = false;
    }
}

class Agent {
    action_space: number[];

    constructor(action_space: number[]) {
        this.action_space = action_space;
    }

    act(): number {
        return this.action_space[Math.floor(Math.random() * this.action_space.length)];
    }
}

function train(agent: Agent, env: Environment, episodes: number, max_steps: number): void {
    for (let episode = 0; episode < episodes; episode++) {
        env.reset();
        for (let step = 0; step < max_steps; step++) {
            const action = agent.act();
            const [_, _, done] = env.step(action);
            if (done) {
                break;
            }
        }
    }
}

function main(): void {
    const action_space = [0, 1];
    const agent = new Agent(action_space);
    const env = new Environment();
    const episodes = 100;
    const max_steps = 20;
    train(agent, env, episodes, max_steps);
}

main();