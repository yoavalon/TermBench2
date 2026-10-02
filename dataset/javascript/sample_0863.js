class Environment {
    constructor() {
        this.state = 0;
        this.goal = 5;
    }

    step(action) {
        if (action == 1) {
            this.state += 1;
        }
        if (this.state >= this.goal) {
            return { state: this.state, reward: 1, done: true };
        } else {
            return { state: this.state, reward: -0.1, done: false };
        }
    }
}

class Agent {
    constructor(epsilon, alpha, gamma) {
        this.epsilon = epsilon;
        this.alpha = alpha;
        this.gamma = gamma;
        this.q_table = {};
    }

    select_action(state) {
        if (Math.random() < this.epsilon) {
            return Math.floor(Math.random() * 2);
        } else {
            return Math.max(...(this.q_table[state] || [0, 0]));
        }
    }

    update_q_table(state, action, reward, next_state, done) {
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

function main() {
    const env = new Environment();
    const agent = new Agent(epsilon=0.1, alpha=0.5, gamma=0.9);
    const episodes = 1000;
    for (let episode = 0; episode < episodes; episode++) {
        let state = env.state;
        let done = false;
        while (!done) {
            const action = agent.select_action(state);
            const { state: next_state, reward, done } = env.step(action);
            agent.update_q_table(state, action, reward, next_state, done);
            state = next_state;
        }
    }
}

main();