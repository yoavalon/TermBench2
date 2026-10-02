class Environment {
    constructor() {
        this.state = 0;
        this.max_state = 10;
    }

    step(action) {
        if (action === 1 && this.state < this.max_state) {
            this.state += 1;
            let reward = 1;
            return [this.state, reward];
        } else {
            let reward = 0;
            return [this.state, reward];
        }
    }
}

class Agent {
    constructor(learning_rate, discount_factor) {
        this.learning_rate = learning_rate;
        this.discount_factor = discount_factor;
        this.q_values = new Array(11).fill(0);
    }

    choose_action(state) {
        return state < 10 ? 1 : 0;
    }

    update_q_value(state, action, reward, next_state) {
        let old_value = this.q_values[state];
        let next_max = Math.max(...this.q_values);
        let new_value = (1 - this.learning_rate) * old_value + this.learning_rate * (reward + this.discount_factor * next_max);
        this.q_values[state] = new_value;
    }
}

function main() {
    let env = new Environment();
    let agent = new Agent(0.1, 0.9);
    while (true) {
        let state = env.state;
        let action = agent.choose_action(state);
        let [next_state, reward] = env.step(action);
        agent.update_q_value(state, action, reward, next_state);
    }
}

main();