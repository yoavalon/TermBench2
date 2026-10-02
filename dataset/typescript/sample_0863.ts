import * as random from 'random';

class Environment {
    state: number;
    goal: number;

    constructor() {
        this.state = 0;
        this.goal = 5;
    }

    step(action: number): [number, number, boolean] {
        if (action === 1) {
            this.state += 1;
        }
        if (this.state >= this.goal) {
            const reward = 1;
            const done = true;
            return [this.state, reward, done];
        } else {
            const reward = -0.1;
            const done = false;
            return [this.state, reward, done];
        }
    }

    reset(): number {
        this.state = 0;
        return this.state;
    }
}

class Agent {
    epsilon: number;
    alpha: number;
    gamma: number;
    q_table: { [key: number]: number[] };

    constructor(epsilon: number, alpha: number, gamma: number) {
        this.epsilon = epsilon;
        this.alpha = alpha;
        this.gamma = gamma;
        this.q_table = {};
    }

    select_action(state: number): number {
        if (random.float() < this.epsilon) {
            return random.int(0, 1);
        } else {
            return Math.max(...(this.q_table[state] || [0, 0]));
        }
    }

    update_q_table(state: number, action: number, reward: number, next_state: number, done: boolean): void {
        if (!this.q_table[state]) {
            this.q_table[state] = [0, 0];
        }
        if (!this.q_table[next_state]) {
            this.q_table[next_state] = [0, 0];
        }
        const old_value = this.q_table[state][action];
        const next_max = Math.max(...this.q_table[next_state]);
        const new_value = old_value + this.alpha * (reward + this.gamma * next_max - old_value);
        this.q_table[state][action] = new_value;
    }
}

function main(): void {
    const env = new Environment();
    const agent = new Agent(epsilon=0.1, alpha=0.5, gamma=0.9);
    const episodes = 1000;
    for (let episode = 0; episode < episodes; episode++) {
        let state = env.reset();
        let done = false;
        while (!done) {
            const action = agent.select_action(state);
            const [next_state, reward, done] = env.step(action);
            agent.update_q_table(state, action, reward, next_state, done);
            state = next_state;
        }
    }
}

main();