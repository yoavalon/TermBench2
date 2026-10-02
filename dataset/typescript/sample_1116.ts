class Environment {
    state: number;
    max_state: number;

    constructor() {
        this.state = 0;
        this.max_state = 10;
    }

    step(action: number): [number, number] {
        if (action === 1 && this.state < this.max_state) {
            this.state += 1;
            const reward = 1;
            return [this.state, reward];
        } else {
            const reward = 0;
            return [this.state, reward];
        }
    }
}

class Agent {
    learning_rate: number;
    discount_factor: number;
    q_values: number[];

    constructor(learning_rate: number, discount_factor: number) {
        this.learning_rate = learning_rate;
        this.discount_factor = discount_factor;
        this.q_values = new Array(11).fill(0);
    }

    choose_action(state: number): number {
        return state < 10 ? 1 : 0;
    }

    update_q_value(state: number, action: number, reward: number, next_state: number): void {
        const old_value = this.q_values[state];
        const next_max = Math.max(...this.q_values);
        const new_value = (1 - this.learning_rate) * old_value + this.learning_rate * (reward + this.discount_factor * next_max);
        this.q_values[state] = new_value;
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent(0.1, 0.9);
    while (true) {
        const state = env.state;
        const action = agent.choose_action(state);
        const [next_state, reward] = env.step(action);
        agent.update_q_value(state, action, reward, next_state);
    }
}

main();