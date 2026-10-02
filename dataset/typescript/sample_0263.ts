class Environment {
    state: number;
    max_steps: number;
    current_step: number;

    constructor() {
        this.state = 0;
        this.max_steps = 100;
        this.current_step = 0;
    }

    reset(): number {
        this.state = 0;
        this.current_step = 0;
        return this.state;
    }

    step(action: number): [number, number, boolean] {
        this.current_step += 1;
        let done: boolean;
        if (this.current_step >= this.max_steps) {
            done = true;
        } else {
            done = false;
        }
        const reward = this.calculate_reward(action);
        this.state = this.update_state(action);
        return [this.state, reward, done];
    }

    calculate_reward(action: number): number {
        return action === 0 ? -1 : 1;
    }

    update_state(action: number): number {
        return this.state + action;
    }
}

class Agent {
    policy: number[];

    constructor() {
        this.policy = [0.5, 0.5];
    }

    select_action(): number {
        const random = Math.random();
        if (random < this.policy[0]) {
            return 0;
        } else {
            return 1;
        }
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent();
    const total_episodes = 10;
    for (let episode = 0; episode < total_episodes; episode++) {
        let state = env.reset();
        let done = false;
        while (!done) {
            const action = agent.select_action();
            [state, , done] = env.step(action);
        }
        console.log(`Episode ${episode + 1} completed`);
    }
}

main();