class Environment {
    constructor() {
        this.state = 0;
        this.terminal_state = 10;
        this.rewards = Array.from({ length: this.terminal_state }, (_, i) => i + 1);
    }

    step(action) {
        if (this.state + action > this.terminal_state) {
            return [this.state, 0, true];
        }
        this.state += action;
        const reward = this.rewards[this.state - 1];
        return [this.state, reward, this.state === this.terminal_state];
    }
}

class Agent {
    constructor(alpha, gamma) {
        this.alpha = alpha;
        this.gamma = gamma;
        this.q_table = new Array(11).fill(0);
    }

    choose_action(state) {
        if (Math.random() > 0.5) {
            return 1;
        } else {
            return 2;
        }
    }

    learn(state, action, reward, next_state) {
        const td_target = reward + this.gamma * Math.max(...this.q_table.slice(next_state));
        const td_error = td_target - this.q_table[state + action - 1];
        this.q_table[state + action - 1] += this.alpha * td_error;
    }
}

function main() {
    const env = new Environment();
    const agent = new Agent(0.1, 0.99);
    const episodes = 1000;
    for (let _ = 0; _ < episodes; _++) {
        let state = env.state;
        while (true) {
            const action = agent.choose_action(state);
            const [next_state, reward, done] = env.step(action);
            agent.learn(state, action, reward, next_state);
            state = next_state;
            if (done) {
                break;
            }
        }
    }
}

main();