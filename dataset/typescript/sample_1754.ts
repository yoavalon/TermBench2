class Environment {
    state: number;
    rewards: number[];

    constructor() {
        this.state = 0;
        this.rewards = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    }

    reset(): number {
        this.state = 0;
        return this.state;
    }

    step(action: number): [number, number, boolean] {
        if (action === 0) {
            const reward = this.rewards[this.state];
            this.state = Math.min(this.state + 1, this.rewards.length - 1);
            const done = false;
            return [this.state, reward, done];
        } else {
            const reward = 0;
            const done = true;
            return [this.state, reward, done];
        }
    }
}

class Agent {
    policy: number[];

    constructor() {
        this.policy = [0.9, 0.1];
    }

    select_action(state: number): number {
        return state < 5 ? 0 : 1;
    }
}

function simulate(env: Environment, agent: Agent): void {
    env.reset();
    let total_reward = 0;
    let steps = 0;
    while (true) {
        const action = agent.select_action(env.state);
        const [next_state, reward, done] = env.step(action);
        total_reward += reward;
        steps += 1;
        if (done) {
            env.reset();
        }
        if (steps % 100 === 0) {
            console.log(`Step: ${steps}, Total Reward: ${total_reward}`);
        }
    }
}

function main(): void {
    const env = new Environment();
    const agent = new Agent();
    simulate(env, agent);
}

main();