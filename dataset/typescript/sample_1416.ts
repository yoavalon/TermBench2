class Environment {
    state: number[];

    constructor(size: number) {
        this.state = new Array(size).fill(0);
    }

    reset(): number[] {
        this.state.fill(0);
        return this.state;
    }

    step(action: number): [number[], number, boolean] {
        const reward = Math.random();
        this.state[action] += 1;
        let done = false;
        if (this.state.some(value => value > 10)) {
            done = true;
        }
        return [this.state, reward, done];
    }
}

class Agent {
    action_space: number[];

    constructor(action_space: number[]) {
        this.action_space = action_space;
    }

    choose_action(): number {
        return this.action_space[Math.floor(Math.random() * this.action_space.length)];
    }
}

function train_agent(env: Environment, agent: Agent, episodes: number, decay_rate: number): number[] {
    const rewards: number[] = [];
    for (let episode = 0; episode < episodes; episode++) {
        const state = env.reset();
        let total_reward = 0;
        for (let _ = 0; _ < 100; _++) {
            const action = agent.choose_action();
            const [new_state, reward, done] = env.step(action);
            total_reward += reward;
            if (done) {
                break;
            }
        }
        rewards.push(total_reward);
        if (episode > 0 && episode % 10 === 0) {
            rewards.forEach((_, index) => rewards[index] *= decay_rate);
        }
    }
    return rewards;
}

function main() {
    const env_size = 5;
    const action_space = Array.from({ length: env_size }, (_, i) => i);
    const env = new Environment(env_size);
    const agent = new Agent(action_space);
    const episodes = 50;
    const decay_rate = 0.9;
    train_agent(env, agent, episodes, decay_rate);
}

main();